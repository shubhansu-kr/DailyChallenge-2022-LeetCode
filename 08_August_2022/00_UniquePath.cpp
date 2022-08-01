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