// https://leetcode.com/problems/range-sum-query-mutable/

// Given an integer array nums, handle multiple queries of the following types:
// Update the value of an element in nums.
// Calculate the sum of the elements of nums between indices left and
// right inclusive where left <= right.
// Implement the NumArray class:
// NumArray(int[] nums) Initializes the object with the integer array nums.
// void update(int index, int val) Updates the value of nums[index] to
// be val.
// int sumRange(int left, int right) Returns the sum of the elements of
// nums between indices left and right inclusive (i.e. nums[left] +
// nums[left + 1] + ... + nums[right]).

#include <bits/stdc++.h>
using namespace std;

class NumArray1
{
    // Optimised : TLE 
public:
    vector<int> nums;
    vector<int> sum;
    NumArray1(vector<int> &nums) : nums(nums) {
        int s = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            s += nums[i];
            sum.emplace_back(s);
        }
    }

    void update(int index, int val)
    {
        int diff = val - nums[index];
        nums[index] = val;
        for (int i = index; i < sum.size(); ++i){sum[i]+=diff;}       
    }

    int sumRange(int left, int right)
    {
        return (sum[right]-sum[left]+nums[left]);
    }
};

class NumArray
{
    // BruteForce: TLE
public:
    vector<int> nums;
    NumArray(vector<int> &nums) : nums(nums) {}

    void update(int index, int val)
    {
        nums[index] = val;
    }

    int sumRange(int left, int right)
    {
        int sum = 0;
        for (int i = left; i <= right; ++i)
        {
            sum += nums[i];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}