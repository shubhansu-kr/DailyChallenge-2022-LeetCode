// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool isValid(vector<int>&pos1, vector<int>&pos2)
    {
        if (pos1[0] == pos2[0]) return true;
        if (pos1[1] == pos2[1]) return true;
        return false;
    }
    void dfs(vector<vector<int>>&stones, vector<bool>&visited, int currIdx)
    {
        visited[currIdx] = true;
        for (int i = 0; i < stones.size(); i++)
        {
            if (visited[i]) continue;
            if (isValid(stones[i], stones[currIdx]))  dfs(stones, visited, i);
        }
    }
    int removeStones(vector<vector<int>>& stones)
    {
        int n = stones.size();
        vector<bool>visited(n, false);
        int componentCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i]) continue;
            dfs(stones, visited, i);
            componentCount++;
        }
        return (n - componentCount); 
    }
};

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