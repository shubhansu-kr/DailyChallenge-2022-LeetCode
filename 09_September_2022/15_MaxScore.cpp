// https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;
    int solve(int i,int n,int k,vector<int> &nums,vector<int> &multipliers){
        if(k==multipliers.size()){
            return 0;
        }
        if(dp[i][k]!=INT_MIN)return dp[i][k];
        int x=solve(i+1,n,k+1,nums,multipliers)+(nums[i]*multipliers[k]);
        int y=solve(i,n,k+1,nums,multipliers)+(nums[(n-1)-(k-i)]*multipliers[k]);
        return dp[i][k]=max(x,y);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n=nums.size(), m=multipliers.size();
        dp.resize(m+1,vector<int>(m+1,INT_MIN));
        return solve(0,n,0,nums,multipliers);
    }
};

class Solution
{
public:
    int dp[1001][1001] = {};
    int dfs(vector<int> &nums, vector<int> &multipliers, int l, int i)
    {
        if (i >= multipliers.size())
            return 0;
        if (!dp[l][i])
        {
            int r = nums.size() - 1 - (i - l);
            dp[l][i] = max(nums[l] * multipliers[i] + dfs(nums, multipliers, l + 1, i + 1),
                           nums[r] * multipliers[i] + dfs(nums, multipliers, l, i + 1));
        }
        return dp[l][i];
    }
    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        return dfs(nums, multipliers, 0, 0);
    }
};

class Solution
{
public:
    int l = 0, r = 0;
    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        r = nums.size() - 1;
        return solve(nums, multipliers);
    }
    int solve(vector<int> &nums, vector<int> &multipliers, int i = 0)
    {
        if (i == multipliers.size()) return 0;

        int left = nums[l++] * multipliers[i] + solve(nums, multipliers, i + 1);
        int right = nums[r--] * multipliers[i] + solve(nums, multipliers, i + 1);

        return max(left, right);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}