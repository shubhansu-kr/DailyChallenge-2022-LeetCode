// https://leetcode.com/problems/3sum-closest/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        if (nums.size() < 3) return 0;
        int closest = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for (int first = 0; first < nums.size() - 2; ++first)
        {
            if (first > 0 && nums[first] == nums[first - 1]) continue;
            int second = first + 1;
            int third = nums.size() - 1;
            while (second < third)
            {
                int curSum = nums[first] + nums[second] + nums[third];
                if (curSum == target) return curSum;
                if (abs(target - curSum) < abs(target - closest)) closest = curSum;
                if (curSum > target) --third;
                else ++second;
            }
        }
        return closest;
    }
};

class Solution
{
    // WA
    // [-100,-98,-2,-1]
    // -101
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        vector<vector<int>> dp(nums.size(), vector<int>(4, -1));
        return solve(nums, dp, target, nums.size() - 1);
    }
    int solve(vector<int> &nums, vector<vector<int>> &dp, int &target, int i, int n = 3)
    {
        if (n == 0 || i == -1)
            return n ? 1e9 : 0;
        if (dp[i][n] != -1)
            return dp[i][n];

        int pick = 0, noPick = 0;
        pick = nums[i] + solve(nums, dp, target, i - 1, n - 1);
        noPick = solve(nums, dp, target, i - 1, n);

        // cannot compare on every step;
        return dp[i][n] = (abs(pick - target) < abs(noPick - target)) ? pick : noPick;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}