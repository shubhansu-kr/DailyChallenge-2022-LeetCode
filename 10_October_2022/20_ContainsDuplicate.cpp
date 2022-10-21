// https://leetcode.com/problems/contains-duplicate-ii/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Let's use a sliding window. 
            unordered_map<int, int> freq;
            int p = 0, q = 0;
            while(q < nums.size()){
                if (q - p > k) {freq[nums[p]]--; ++p;}

                if (freq[nums[q]]) return true;
                else freq[nums[q]]++;

                ++q;
            }
            return false;        
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums = {1, 2, 3, 1};
    int k = 3; 

    Solution Obj1; 
    cout << Obj1.containsNearbyDuplicate(nums, k);
    return 0;
}