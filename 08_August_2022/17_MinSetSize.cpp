// https://leetcode.com/problems/reduce-array-size-to-the-half/


// You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.

// Return the minimum size of the set so that at least half of the integers of the array are removed.

#include <bits/stdc++.h>
using namespace std ;

class Solution3 {
    // Clean and Concise: count sort
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (int x : arr) ++cnt[x];
        
        vector<int> frequencies;
        for (auto [_, freq] : cnt) frequencies.push_back(freq);
        sort(frequencies.begin(), frequencies.end());
        
        int ans = 0, removed = 0, half = arr.size() / 2, i = frequencies.size() - 1;
        while (removed < half) {
            ans += 1;
            removed += frequencies[i--];
        }
        return ans;
    }
};

class Solution2 {
    // Using Maps: Tabulation : TLE 
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> m;
        for(auto &it: arr) {m[it]++;}
        vector<int> nums;
        for(auto &it: m) nums.emplace_back(it.second);
        // Now we just have to find the min. number of elements from 
        // nums which add upto half of the size of arr.
        int n = arr.size(); 
        vector<vector<int>> dp(nums.size(), vector<int> (n/2+1, 0));

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int k = 1; k <= n/2; ++k)
            {
                int pick = 1e9, noPick = 1e9;
                if (i > 0) {
                    if (k - nums[i] > 0) {
                        pick = 1 + dp[i-1][k-nums[i]]; 
                    } 
                    else {
                        pick = 1 ;
                    }
                    noPick = dp[i-1][k];
                }
                dp[i][k] = min(pick, noPick);
            }
        }
        
        return dp[nums.size()-1][n/2];
    }
};

class Solution1 {
    // Using Maps: Recursion Memoization
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> m;
        for(auto &it: arr) {m[it]++;}
        vector<int> nums;
        for(auto &it: m) nums.emplace_back(it.second);
        // Now we just have to find the min. number of elements from 
        // nums which add upto half of the size of arr.
        int n = arr.size(); 
        vector<vector<int>> dp(nums.size(), vector<int> (n/2+1, -1));
        return solve(nums, dp, n/2, nums.size()-1);
    }
    int solve(vector<int> &nums, vector<vector<int>> &dp, int k, int i) {
        if (k <= 0) return 0;
        if (i == -1) return 1e9;
        if (dp[i][k] != -1) return dp[i][k]; 
        // Pick 
        int pick = 1 + solve(nums, dp, k-nums[i], i-1);
        int noPick = solve(nums, dp, k, i-1);

        return dp[i][k] = min(pick, noPick);
    }
};

class Solution {
    // Using Maps: Recursion BruteForce 
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> m;
        for(auto &it: arr) {m[it]++;}
        vector<int> nums;
        for(auto &it: m) nums.emplace_back(it.second);
        // Now we just have to find the min. number of elements from 
        // nums which add upto half of the size of arr.
        int n = arr.size(); 
        return solve(nums, n/2, nums.size()-1);
    }
    int solve(vector<int> &nums, int k, int i) {
        if (k <= 0) return 0;
        if (i == -1) return 1e9;
        
        // Pick 
        int pick = 1 + solve(nums, k-nums[i], i-1);
        int noPick = solve(nums, k, i-1);

        return min(pick, noPick);
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}