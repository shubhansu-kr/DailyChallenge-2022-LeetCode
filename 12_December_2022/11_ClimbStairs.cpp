// https://leetcode.com/problems/climbing-stairs/

#include <bits/stdc++.h>
using namespace std ;

class Solution1 {
    // Memoization
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return countWays(n, dp);
    }
    int countWays(int n, vector<int> &dp) {
        if (n <= 0) return n == 0;
        if (dp[n] != -1) return dp[n];
        return dp[n] = countWays(n-1, dp) + countWays(n-2, dp);
    }
};

class Solution {
    // BruteForce : Recursion 
public:
    int climbStairs(int n) {
        if (n <= 0) return n == 0;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

int main () {
    
    return 0;
}