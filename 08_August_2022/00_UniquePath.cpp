// https://leetcode.com/problems/unique-paths/

// There is a robot on an m x n grid. The robot is initially located at 
// the top-left corner (i.e., grid[0][0]). The robot tries to move to the 
// bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move 
// either down or right at any point in time.

// Given the two integers m and n, return the number of possible unique 
// paths that the robot can take to reach the bottom-right corner.

// The test cases are generated so that the answer will be less than or 
// equal to 2 * 109.


#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // Recursion: Memoization 
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        return findPath (m-1, n-1, dp);
    }

    int findPath (int i, int j, vector<vector<int>> &dp) {
        if (i < 0 || j < 0) return 0;
        if (i == 0 && j == 0) return 1;
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = findPath(i-1, j, dp) + findPath(i, j-1, dp);
    }
};

class Solution {
    // BruteForce: Recursion 
public:
    int uniquePaths(int m, int n) {
        if (m == 1 && n == 1) {return 1;}

        int up = 0 ;
        if (m > 1) {up = uniquePaths(m-1, n);}
        int left = 0 ;
        if (n > 1) {left = uniquePaths(m, n-1);}
        return up + left ;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}