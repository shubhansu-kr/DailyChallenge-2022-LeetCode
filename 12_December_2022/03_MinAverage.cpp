// https://leetcode.com/problems/minimum-average-difference/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumAverageDifference(vector<int> &nums)
    {
        int n(size(nums)), minAverageDifference(INT_MAX), index;
        long long sumFromFront(0), sumFromEnd(0);
        for (auto &num : nums) sumFromEnd += num;

        for (int i = 0; i < n; i++)
        {
            sumFromFront += nums[i];
            sumFromEnd -= nums[i];
            int a = sumFromFront / (i + 1);                      
            int b = (i == n - 1) ? 0 : sumFromEnd / (n - i - 1); 

            if (abs(a - b) < minAverageDifference)
            {
                minAverageDifference = abs(a - b);
                index = i;
            }
        }
        return index;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}