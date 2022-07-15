// https://leetcode.com/problems/max-area-of-island/

// You are given an m x n binary matrix grid. An island is a group 
// of 1's (representing land) connected 4-directionally (horizontal 
// or vertical.) You may assume all four edges of the grid are surrounded 
// by water.
// The area of an island is the number of cells with a value 1 in the island.
// Return the maximum area of an island in grid. If there is no island, 
// return 0.

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int dfs(vector<vector<int>>&grid,int i,int j,int n,int m)
    {
        if(i>=0 and i<n and j>=0 and j<m and grid[i][j]==1){grid[i][j]=0;return 1+ dfs(grid,i+1,j,n,m)+dfs(grid,i-1,j,n,m)+dfs(grid,i,j+1,n,m)+dfs(grid,i,j-1,n,m);}
        return 0;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int max_area=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    int count=dfs(grid,i,j,n,m);
                    max_area=max(max_area,count);
                }
            }
        }
        return max_area;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}