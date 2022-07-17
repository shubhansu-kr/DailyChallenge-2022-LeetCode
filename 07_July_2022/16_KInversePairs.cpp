// https://leetcode.com/problems/k-inverse-pairs-array/

// For an integer array nums, an inverse pair is a pair of integers
// [i, j] where 0 <= i < j < nums.length and nums[i] > nums[j].

// Given two integers n and k, return the number of different arrays
// consist of numbers from 1 to n such that there are exactly k inverse
// pairs. Since the answer can be huge, return it modulo 109 + 7.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // TLE
public:
    int kInversePairs(int n, int k)
    {
        int dp[2][1001] = {1};
        for (int N = 1; N <= n; ++N)
            for (int K = 0; K <= k; ++K)
            {
                dp[N % 2][K] = (dp[(N - 1) % 2][K] + (K > 0 ? dp[N % 2][K - 1] : 0)) % 1000000007;
                if (K >= N)
                    dp[N % 2][K] = (1000000007 + dp[N % 2][K] - dp[(N - 1) % 2][K - N]) % 1000000007;
            }
        return dp[n % 2][k];
    }
};

class Solution
{
    // TLE
public:
    int dp[1001][1001] = {};
    int kInversePairs(int n, int k)
    {
        if (k <= 0)
            return k == 0;
        if (dp[n][k] == 0)
        {
            dp[n][k] = 1;
            for (auto i = 0; i < n; ++i)
            {
                dp[n][k] = (dp[n][k] + kInversePairs(n - 1, k - i)) % 1000000007;
            }
        }
        return dp[n][k] - 1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}