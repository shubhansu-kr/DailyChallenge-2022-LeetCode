// https://leetcode.com/problems/longest-subsequence-with-limited-sum/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i)
        {
            nums[i] = nums[i] + nums[i-1];
        }
        vector<int> ans;
        for (int i = 0; i < queries.size(); ++i)
        {
            int flag = 1;
            for (int j = 0; j < nums.size(); ++j)
            {
                if(nums[j] > queries[i]) {
                    ans.emplace_back(j);
                    flag = 0;
                    break;
                }
            }
            if (flag) ans.emplace_back(nums.size());
        }
        return ans;
    }
};

int main () {
    
    return 0;
}