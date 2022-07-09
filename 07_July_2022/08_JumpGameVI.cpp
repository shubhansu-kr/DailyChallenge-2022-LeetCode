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

class Solution4
{
    // Discussion Solution 
public:
    int maxResult(vector<int> &nums, int k)
    {
        long curr = 0;
        deque<int> dq; // Monoqueue

        // Start answering the best possible results for index `i` from the back
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            curr = nums[i] + (dq.empty() ? 0 : nums[dq.front()]); // Get current best, the maximum result will be the first element in the monoqueue.

            // We remove all the smaller results greedily as they wont get used anyways (This helps the monoqueue to remain sorted)
            while (!dq.empty() && curr > nums[dq.back()])
                dq.pop_back();
            dq.push_back(i); // Insert current index into the monoqueue

            // Erase all the indices in deque that are greater than or equal to i+k.
            if (dq.front() >= i + k)
                dq.pop_front();
            nums[i] = curr; // Use input array as auxillary array to store the best results.
        }
        return curr; // `curr` would have the best or the maxium result to reach end from index 0.
    }
};

class Solution3
{
    // Tabulation
public:
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];

        for (int j = 1; j < n; ++j)
        {
            int subMax = INT_MIN;
            for (int i = 1; i <= k; ++i)
            {
                if (j - i < 0)
                    break;

                int sum = nums[j] + dp[j - i];
                subMax = max(sum, subMax);
            }
            dp[j] = subMax;
        }
        return dp[n - 1];
    }
};

class Solution2
{
    // Recursion: Memoization
public:
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(nums, dp, k, n - 1) + nums[n - 1];
    }

    int solve(vector<int> &nums, vector<int> &dp, int &k, int n)
    {
        // base condition
        if (n <= 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int subMax = INT_MIN;
        for (int i = 1; i <= k; ++i)
        {
            if (n - i < 0)
                break;
            int sum = nums[n - i] + solve(nums, dp, k, n - i);
            subMax = max(sum, subMax);
        }

        return subMax;
    }
};

class Solution1
{
    // Recursion: Optimised
public:
    int maxResult(vector<int> &nums, int k)
    {
        int n = nums.size();
        return solve(nums, k, n - 1) + nums[n - 1];
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

    Solution3 obj1;
    cout << obj1.maxResult(nums, k);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}