// https://leetcode.com/problems/sum-of-even-numbers-after-queries/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &nums, vector<vector<int>> &queries)
    {
        vector<int> ans;
        int sum = 0 ;
        for(auto &a: nums){
            if (a % 2 == 0) sum += a;
        }
        for (int i = 0; i < queries.size(); ++i)
        {
            int x = nums[queries[i][1]];
            if (x % 2 == 0) {sum -= x;}
            x += queries[i][0];
            if (x % 2 == 0) sum += x;
            nums[queries[i][1]] = x; 
            ans.emplace_back(sum);
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}