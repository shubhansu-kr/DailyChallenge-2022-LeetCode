// https://leetcode.com/problems/maximum-performance-of-a-team/

#include <bits/stdc++.h>
using namespace std ;


class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        vector<vector<int>> worker;
        vector<int> tmp(2,0);
        for (int i = 0; i < n; i++) {
            tmp[0] = speed[i];
            tmp[1] = efficiency[i];
            worker.push_back(tmp);
        }
        sort(worker.begin(), worker.end(), compare);
        long res = 0;
        long total = 0;
        long minE;
        for (int i = 0; i < k; i++) {
            total += worker[i][0];
            minE = worker[i][1];
            res = max(res, total*minE);
            heap.push(worker[i][0]);
        }
        for (int i = k; i < n; i++) {
            if (worker[i][0] > heap.top()) {
                total += (-heap.top()+worker[i][0]);
                minE = worker[i][1];
                res = max(res, total*minE);
                heap.pop();
                heap.push(worker[i][0]);
            }
        }
        return (int)(res%1000000007);
    }
    
    static bool compare(vector<int>& w1, vector<int>& w2) {
        return w1[1] > w2[1];
    }
};

class Solution {
    // BruteForce: Recursion: TLE 
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        int mini = INT_MAX;
        return solve(speed, efficiency, 0, mini, k, n-1);
    }
    int solve(vector<int> &speed, vector<int> &efficiency, int sum, int mini, int k, int i) {
        if(i < 0 || k == 0) {
            return (sum * mini)%1000000007;
        }
        
        int pick = solve(speed, efficiency, sum+speed[i], min(efficiency[i], mini), k-1, i-1);
        int noPick = solve(speed, efficiency, sum, mini, k, i-1);

        return max(pick, noPick);
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}