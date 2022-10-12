// https://leetcode.com/problems/largest-perimeter-triangle/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(), nums.end());
        for (int i = nums.size()-1; i > 1; --i)
        {
            int x = nums[i];
            if (x < nums[i-1]+nums[i-2]) {
                sum = nums[i] + nums[i-1] + nums[i-2];
                break;
            }
        }
        return sum;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}