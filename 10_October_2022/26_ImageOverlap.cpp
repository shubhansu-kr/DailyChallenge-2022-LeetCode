// https://leetcode.com/problems/image-overlap/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<int> LA, LB;
        int N = img1.size();
        unordered_map<int, int> count;
        for (int i = 0; i < N * N; ++i)
            if (img1[i / N][i % N] == 1)
                LA.push_back(i / N * 100 + i % N);
        for (int i = 0; i < N * N; ++i)
            if (img2[i / N][i % N] == 1)
                LB.push_back(i / N * 100 + i % N);
        for (int i : LA) for (int j : LB) count[i - j]++;
        int res = 0;
        for (auto it : count) res = max(res, it.second);
        return res;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}