// https://leetcode.com/problems/reduce-array-size-to-the-half/


// You are given an integer array arr. You can choose a set of integers and remove all the occurrences of these integers in the array.

// Return the minimum size of the set so that at least half of the integers of the array are removed.

#include <bits/stdc++.h>
using namespace std ;

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
        if (i == -1 || k <= 0) return 0;
        
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