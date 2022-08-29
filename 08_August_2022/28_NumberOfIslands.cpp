// https://leetcode.com/problems/number-of-islands/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> r = {-1, 0, 1, 0};
    vector<int> c = {0, 1, 0, -1};
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                if (grid[i][j] == '1') {
                    ans++;
                    DFS(grid, i, j);
                }
            }
        }
        return ans;
    }
    void DFS(vector<vector<char>> &grid, int i, int j) {
        grid[i][j] = '0';
        int row, col;
        for (int k = 0; k < 4; ++k)
        {
            row = i + r[k] ;        
            col = j + c[k] ;  

            if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size()) continue;
            
            if (grid[row][col] == '1') {DFS(grid, row, col);}
        }
        return ;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}