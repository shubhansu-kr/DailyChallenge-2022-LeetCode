// https://leetcode.com/problems/split-array-into-consecutive-subsequences/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // BruteForce: Intution
    // WrongAnswer: The size of subsequence can be greater than 3: 
public:
    bool isPossible(vector<int> &nums)
    {
        // Edge Case
        if (nums.size() < 3) return false;

        vector<int> visited(nums.size(), 0);
        stack<int> s;
        int prev = -1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (visited[i]) continue;
            if (s.size() == 3)
            {
                while (s.size()) s.pop();
                if (prev == -1){--i;continue;}
                else{i = prev - 1, prev = -1;}
            }

            if (!s.size())
            {
                s.push(nums[i]);
                visited[i] = 1;
            }
            else
            {
                if (nums[i] == s.top())
                {
                    if (prev == -1) prev = i;
                    continue;
                }
                else if (nums[i] - s.top() == 1)
                {
                    s.push(nums[i]);
                    visited[i] = 1;
                }
                else
                {
                    return false;
                }
            }
        }
        return s.size() == 3;
    }
};

int main()
{
    vector<int> nums = {1,2,3,3,4,5};

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}