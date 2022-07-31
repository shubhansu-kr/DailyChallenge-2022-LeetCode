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

class BIT { // One-based indexing
    vector<int> bit;
public:
    BIT(int size=0) {
        bit.assign(size + 1, 0);
    }
    int getSum(int idx) { // Get sum in range [1..idx]
        int sum = 0;
        for (; idx > 0; idx -= idx & (-idx))
            sum += bit[idx];
        return sum;
    }
    void addValue(int idx, int val) {
        for (; idx < bit.size(); idx += idx & (-idx))
            bit[idx] += val;
    }
};
class NumArray {
    BIT bit;
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        this->bit = BIT(nums.size());
        this->nums = nums;
        for (int i = 0; i < nums.size(); ++i)
            bit.addValue(i+1, nums[i]);
    }
    void update(int index, int val) {
        int diff = val - nums[index]; // get diff amount of `val` compared to current value
        bit.addValue(index + 1, diff); // add this `diff` amount at index `index+1` of BIT, plus 1 because in BIT it's 1-based indexing
        nums[index] = val; // update latest value of `nums[index]`
    }
    int sumRange(int left, int right) {
        return bit.getSum(right+1) - bit.getSum(left);
    }
};

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