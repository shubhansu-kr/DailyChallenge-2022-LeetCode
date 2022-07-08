// https://leetcode.com/problems/paint-house-iii/

// There is a row of m houses in a small city, each house must be painted
// with one of the n colors (labeled from 1 to n), some houses that have
// been painted last summer should not be painted again.
// A neighborhood is a maximal group of continuous houses that are
// painted with the same color.
// For example: houses = [1,2,2,3,3,2,1,1] contains 5 neighborhoods
// [{1}, {2,2}, {3,3}, {2}, {1,1}].
// Given an array houses, an m x n matrix cost and an integer target where:
// houses[i]: is the color of the house i, and 0 if the house is not
// painted yet.
// cost[i][j]: is the cost of paint the house i with the color j + 1.
// Return the minimum cost of painting all the remaining houses in
// such a way that there are exactly target neighborhoods. If it is
// not possible, return -1.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dp[101][101][21] = {};
    int dfs(vector<int> &houses, vector<vector<int>> &cost, int i, int target, int last_clr)
    {
        if (i >= houses.size() || target < 0)
            return target == 0 ? target : 1000001;
        if (houses[i] != 0) // painted last year.
            return dfs(houses, cost, i + 1, target - (last_clr != houses[i]), houses[i]);
        if (dp[i][target][last_clr])
            return dp[i][target][last_clr];
        auto res = 1000001;
        for (auto clr = 1; clr <= cost[i].size(); ++clr)
        {
            res = min(res, cost[i][clr - 1] + dfs(houses, cost, i + 1, target - (last_clr != clr), clr));
        }
        return dp[i][target][last_clr] = res;
    }
    int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target)
    {
        auto res = dfs(houses, cost, 0, target, 0);
        return res > 1000000 ? -1 : res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}