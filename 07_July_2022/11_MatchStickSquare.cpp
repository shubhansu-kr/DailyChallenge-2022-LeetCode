// https://leetcode.com/problems/matchsticks-to-square/

// You are given an integer array matchsticks where matchsticks[i] is 
// the length of the ith matchstick. You want to use all the matchsticks 
// to make one square. You should not break any stick, but you can link 
// them up, and each matchstick must be used exactly one time.
// Return true if you can make this square and false otherwise.

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        long long len = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (len % 4) return false; 
        else len /= 4 ;

        // if any of the element is greater than len return false ;
        for(auto &it: matchsticks) if (it > len) return false; 

        // Find all the subsets which sum to 2*len 
        vector<int> v1;
        return solve(matchsticks, v1, len, 2*len, matchsticks.size()-1);
    }

    bool solve (vector<int> &nums, vector<int> &v1,  int t, int k, int n) {
        if (n == -1 || k == 0) {
            if (k == 0) {
                vector<int> v2;
                return (divide(v1, t, v1.size()-1) && divide(v2, t, v2.size()-1));
            }
            return false;
        }

        bool pick = false ;
        if (k >= nums[0]) {
            v1.emplace_back(nums[n]);
            pick = solve(nums, v1, t, k-nums[n], n-1);
            v1.pop_back();
            if (pick) return true;
        }   
        bool noPick = solve(nums, v1, t, k, n-1);  
        return pick || noPick;
    }

    // Check if subset with sum k exists 
    bool divide(vector<int> &nums, int k, int n) {
        // Base condition 
        if (n == 0) return k == nums[0];
        if (k == 0) return true;

        bool pick = false; 
        if (nums[n] <= k) pick = divide(nums, k-nums[n], n-1);
        bool noPick = divide(nums, k, n-1);

        return pick || noPick;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}