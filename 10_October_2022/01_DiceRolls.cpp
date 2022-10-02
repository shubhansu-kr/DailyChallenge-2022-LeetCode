// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

#include <bits/stdc++.h>
using namespace std ;

// class Solution {
//     // Tabulation 
// public:
//     int mod = 1e9+7;
//     int numRollsToTarget(int n, int k, int target) {
//         vector<vector<int>> dp(n, vector<int>(target+1));
//         for (int j = 0; j < target+1; ++j)
//         {
//             dp[0][j] = (j == target);
//         }
        
//         return solve(target, k, n, dp, n-1);
//     }

//     int solve(int &target, int &k, int &n, vector<vector<int>> &dp, int i, int sum = 0) {
//         if (i == -1 || sum > target) {
//             return (sum == target);
//         };

//         if (dp[i][sum] != -1) return dp[i][sum];
//         long ways = 0;
//         for (int j = 1; j < k+1; ++j)
//         {
//             ways += solve(target, k, n, dp, i-1, sum+j);
//         }
//         ways %= mod;
//         return dp[i][sum] = ways;
//     }
// };

class Solution {
    // Recursion: Memoization 
public:
    int mod = 1e9+7;
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return solve(target, k, n, dp);
    }

    int solve(int &target, int &k, int &n, vector<vector<int>> &dp, int sum = 0, int i = 0) {
        if (i == n || sum > target) {
            return (sum == target);
        };

        if (dp[i][sum] != -1) return dp[i][sum];
        long ways = 0;
        for (int j = 1; j < k+1; ++j)
        {
            ways += solve(target, k, n, dp, sum+j, i+1);
        }
        ways %= mod;
        return dp[i][sum] = ways;
    }
};

class Solution {
    // BruteForce: Recursion 
public:
    int numRollsToTarget(int n, int k, int target) {
        int count = 0;
        solve(target, k, n, count);
        return count;
    }

    void solve(int &target, int &k, int &n, int &count, int sum = 0, int i = 0) {
        if (i == n || sum > target) {
            count += (sum == target);
            return;
        };
        for (int j = 1; j < k+1; ++j)
        {
            solve(target, k, n, count, sum+j, i+1);
        }
        return;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}