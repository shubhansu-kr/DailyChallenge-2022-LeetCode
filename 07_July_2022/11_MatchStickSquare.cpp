// https://leetcode.com/problems/matchsticks-to-square/

// You are given an integer array matchsticks where matchsticks[i] is 
// the length of the ith matchstick. You want to use all the matchsticks 
// to make one square. You should not break any stick, but you can link 
// them up, and each matchstick must be used exactly one time.
// Return true if you can make this square and false otherwise.

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // Depth first search: Discussion solution 
public:
    
    bool dfs(vector<int> &sidesLength,const vector<int> &matches, int index, const int target) {
        if (index == matches.size()) return sidesLength[0] == sidesLength[1] && sidesLength[1] == sidesLength[2] && sidesLength[2] == sidesLength[3];
        for (int i = 0; i < 4; ++i) {
            if (sidesLength[i] + matches[index] > target) continue;
            int j = i;
            while (--j >= 0) // third
                if (sidesLength[i] == sidesLength[j]) break;
            if (j != -1) continue;
            sidesLength[i] += matches[index];
            if (dfs(sidesLength, matches, index + 1, target)) return true;
            sidesLength[i] -= matches[index];
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        if (matchsticks.size() < 4) return false;
        int sum = 0;
        for (const int val: matchsticks) {
            sum += val;
        }
        if (sum % 4 != 0) return false;
        sort(matchsticks.begin(), matchsticks.end(), [](const int &l, const int &r){return l > r;}); // second
        for(auto &it: matchsticks) if(it > sum/4) return false; 
        vector<int> sidesLength(4, 0);
        return dfs(sidesLength, matchsticks, 0, sum / 4);
    }
};

class Solution {
    // Wrong Solution
public:
    bool makesquare(vector<int>& matchsticks) {
        long long len = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (len % 4) return false; 
        else len /= 4 ;

        // if any of the element is greater than len return false ;
        for(auto &it: matchsticks) if (it > len) return false; 

        // Find all the subsets which sum to 2*len 
        vector<int> v1;
        return solve(matchsticks, v1, len, 2*len, matchsticks.size()-1);
    }

    bool solve (vector<int> &matchsticks, vector<int> &v1,  int t, int k, int n) {
        if (n == -1 || k == 0) {
            if (k == 0) {
                vector<int> v2;
                return (divide(v1, t, v1.size()-1) && divide(v2, t, v2.size()-1));
            }
            return false;
        }

        bool pick = false ;
        if (k >= matchsticks[0]) {
            v1.emplace_back(matchsticks[n]);
            pick = solve(matchsticks, v1, t, k-matchsticks[n], n-1);
            v1.pop_back();
            if (pick) return true;
        }   
        bool noPick = solve(matchsticks, v1, t, k, n-1);  
        return pick || noPick;
    }

    // Check if subset with sum k exists 
    bool divide(vector<int> &matchsticks, int k, int n) {
        // Base condition 
        if (n == 0) return k == matchsticks[0];
        if (k == 0) return true;

        bool pick = false; 
        if (matchsticks[n] <= k) pick = divide(matchsticks, k-matchsticks[n], n-1);
        bool noPick = divide(matchsticks, k, n-1);

        return pick || noPick;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}