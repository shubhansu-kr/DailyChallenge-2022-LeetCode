// https://leetcode.com/problems/continuous-subarray-sum/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, pre = 0;
        unordered_set<int> modk;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            int mod = k == 0 ? sum : sum % k;
            if (modk.count(mod)) return true;
            modk.insert(pre);
            pre = mod;
        }
        return false;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}