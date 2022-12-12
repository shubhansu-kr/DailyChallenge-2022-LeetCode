// https://leetcode.com/problems/climbing-stairs/

#include <bits/stdc++.h>
using namespace std ;

class Solution3 {
    // Tabulation: Space optimisation
public:
    int climbStairs(int n) {
        // vector<int> dp(n+1, -1);
        // dp[0] = 1, dp[1] = 1;
        int prev = 1, prev1 = 1, temp;
        for (int i = 2; i <= n; ++i)
        {
            temp = prev + prev1;
            prev1 = prev;
            prev = temp;
        }
        return prev;
    }
};

class Solution2 {
    // Tabulation
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        dp[0] = 1, dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

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