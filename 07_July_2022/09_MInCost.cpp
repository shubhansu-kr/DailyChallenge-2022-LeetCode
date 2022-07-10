// https://leetcode.com/problems/min-cost-climbing-stairs/

// You are given an integer array cost where cost[i] is the cost of
// ith step on a staircase. Once you pay the cost, you can either climb
// one or two steps.
// You can either start from the step with index 0, or the step with index 1.
// Return the minimum cost to reach the top of the floor.

#include <bits/stdc++.h>
using namespace std;

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
        if (i >= cost.size()) return 0;

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