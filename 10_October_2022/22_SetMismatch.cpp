// https://twitter.com/shubhansu_kr/status/1584221989967126528

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> krs(nums.size());
        for(auto &it: nums){
            krs[it-1]++;
        }
        vector<int> ans(2, 0);
        for (int i = 0; i < krs.size(); ++i)
        {
            if (krs[i] == 0){
                ans[1] = i+1;
            }
            else if (krs[i] == 2){
                ans[0] = i+1 ;
            }
        }
        return ans;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}