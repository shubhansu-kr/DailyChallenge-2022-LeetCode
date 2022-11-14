// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // Since the coordinates are given, we can either create a map or 
    // we can create a matrix by getting the max row and col first 

    // Creating a matrix 
    // WA: Order of picking matters a lot 
public:
    int removeStones(vector<vector<int>>& stones) {
        int row = INT_MIN, col = INT_MIN;
        for(auto &it: stones){
            row = max(row, it[0]);
            col = max(row, it[1]);
        }
        vector<int> r(row+1), c(col+1);
        int ans = 0;
        for (auto &it: stones){
            if (r[it[0]] || c[it[1]]) ++ans;
            else r[it[0]] = c[it[1]] = 1;
        }

        return ans; 
    }
};

class Solution {
    // if the matrix would have been given: WA
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