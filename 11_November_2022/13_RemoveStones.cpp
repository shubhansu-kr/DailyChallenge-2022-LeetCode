// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // if the matrix would have been given 
public:
    int removeStones(vector<vector<int>>& stones) {
        vector<int> row(stones.size()), col(stones[0].size());
        int ans = 0;
        for (int i = 0; i < stones.size(); ++i)
        {
            for (int j = 0; j < stones[i].size(); ++j)
            {
                if (row[i] || col[j]) ++ans;
                else row[i] = col[j] = 1;
            }
        }
        return ans;
    }
};

class Solution {
    // if the matrix would have been given 
public:
    int removeStones(vector<vector<int>>& stones) {
        vector<int> row(stones.size()), col(stones[0].size());
        int ans = 0;
        for (int i = 0; i < stones.size(); ++i)
        {
            for (int j = 0; j < stones[i].size(); ++j)
            {
                if (row[i] || col[j]) ++ans;
                else row[i] = col[j] = 1;
            }
        }
        return ans;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}