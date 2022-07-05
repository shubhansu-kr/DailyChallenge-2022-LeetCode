// https://leetcode.com/problems/longest-consecutive-sequence/

// Given an unsorted array of integers nums, return the length of
// the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // brute Force: Memory Limit Excedded.  
public:
    int longestConsecutive(vector<int> &nums)
    {
        vector<int> v(2000000001, 0);
        for (int &it : nums)
        {
            v[it + 1000000000] = 1;
        }
        int count = 0, maxLen = INT_MIN;
        for (int i = 0; i < v.size(); ++i)
        {
            if (v[i])
            {
                ++count;
            }
            else
            {
                if (count)
                {
                    maxLen = max(maxLen, count);
                    count = 0;
                }
            }
        }
        maxLen = max(maxLen, count);
        return maxLen;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}