// https://leetcode.com/problems/min-cost-climbing-stairs/

// You are given an integer array cost where cost[i] is the cost of
// ith step on a staircase. Once you pay the cost, you can either climb
// one or two steps.
// You can either start from the step with index 0, or the step with index 1.
// Return the minimum cost to reach the top of the floor.

#include <bits/stdc++.h>
using namespace std;

class Solution3
{
    // Tabulation: Space Optimised
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int prev = cost[0], prev1 = cost[1];
        for (int i = 2; i < cost.size(); ++i)
        {
            int temp = prev1;
            prev1 = cost[i] + min(prev, prev1);
            prev = temp;
        }
        return min(prev, prev1);
    }
};

class Solution2
{
    // Tabulation
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n);
        dp[0] = cost[0], dp[1] = cost[1];
        for (int i = 2; i < n; ++i)
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        return min(dp[n - 2], dp[n - 1]);
    }
};

class Solution1
{
    // Recursion: Memoization
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> dp(n, -1);
        solve(cost, dp, 0);
        return min(dp[0], dp[1]);
    }

    int solve(vector<int> &cost, vector<int> &dp, int i)
    {
        if (i >= cost.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        int one = cost[i] + solve(cost, dp, i + 1);
        int two = cost[i] + solve(cost, dp, i + 2);
        return dp[i] = min(one, two);
    }
};

class Solution
{
    // BruteForce: Recursion
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        return min(solve(cost, 0), solve(cost, 1));
    }

    int solve(vector<int> &cost, int i)
    {
        if (i >= cost.size())
            return 0;

        int one = cost[i] + solve(cost, i + 1);
        int two = cost[i] + solve(cost, i + 2);

        return min(one, two);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}