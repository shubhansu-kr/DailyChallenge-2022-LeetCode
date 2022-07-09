// https://leetcode.com/problems/jump-game-vi/

// You are given a 0-indexed integer array nums and an integer k.
// You are initially standing at index 0. In one move, you can jump
// at most k steps forward without going outside the boundaries of
// the array. That is, you can jump from index i to any index in the
// range [i + 1, min(n - 1, i + k)] inclusive.
// You want to reach the last index of the array (index n - 1). Your
// score is the sum of all nums[j] for each index j you visited in the array.
// Return the maximum score you can get.

#include <bits/stdc++.h>
using namespace std;

class Solution1
{
    // Recursion: Optimised 
public:
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();
        return solve(nums, k, n - 1) + nums[n-1];
    }

    int solve(vector<int> &nums, int &k, int n)
    {
        // base condition
        if (n <= 0)
            return 0;

        int subMax = INT_MIN;
        for (int i = 1; i <= k; ++i)
        {
            if (n - i < 0)
                break;
            int sum = nums[n - i] + solve(nums, k, n - i);
            subMax = max(sum, subMax);
        }

        return subMax;
    }
};

class Solution
{
    // BruteForce: Recursion
public:
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size(), sum = nums[n - 1], ans = INT_MIN;
        solve(nums, ans, sum, k, n - 1);
        return ans;
    }

    void solve(vector<int> &nums, int &ans, int &sum, int &k, int n)
    {
        // base condition
        if (n <= 0)
        {
            if (n == 0)
            {
                ans = max(ans, sum);
            }
            return;
        }

        for (int i = 1; i <= k; ++i)
        {
            if (n - i < 0)
                break;

            sum += nums[n - i];
            solve(nums, ans, sum, k, n - i);
            sum -= nums[n - i];
        }
    }
};

int main()
{
    vector<int> nums = {1, -1, -2, 4, -7, 3};
    int k = 2;

    Solution1 obj1;
    cout << obj1.maxResult(nums, k);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}