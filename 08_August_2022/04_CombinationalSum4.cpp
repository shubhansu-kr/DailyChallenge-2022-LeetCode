// https://leetcode.com/problems/combination-sum-iv/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // Wrong Answer 
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size() ;
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return findCount(nums, dp, target, 0, n-1);
    }

    int findCount (vector<int> &nums, vector<vector<int>> &dp, int target, int sum,  int i) {
        if (sum == target) return 1 ;
        if (i == -1 || sum > target || i == nums.size()) return 0 ;
        if (dp[i][sum] != -1) return dp[i][sum];


        int s = findCount(nums, dp, target, sum+nums[i], i);
        int b = findCount(nums, dp, target, sum+nums[i], i-1) + findCount(nums, dp, target, sum, i-1);
        int f = findCount(nums, dp, target, sum+nums[i], i+1) + findCount(nums, dp, target, sum, i+1);
    
        return dp[i][sum] = s + b + f ;
    }
};

int main () {

    vector<int> nums = {3, 1, 5, 6, 8, 4, 2, 8, 9};
    int target = 21;

    Solution Obj1; 
    cout << Obj1.combinationSum4(nums, target);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}