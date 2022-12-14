// https://leetcode.com/problems/house-robber/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int rob(vector<int> &nums)
    {
        int prev=nums[0], prev1 = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            int p = nums[i] + prev1;
            prev1 = prev;
            prev = max(p, prev);
        }
        return prev;
    }
};

int main () {
    
    return 0;
}