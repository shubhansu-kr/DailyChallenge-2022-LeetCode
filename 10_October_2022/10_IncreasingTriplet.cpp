// https://leetcode.com/problems/increasing-triplet-subsequence/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        int c1 = INT_MAX, c2 = INT_MAX;
        for (int x : nums)
        {
            if (x <= c1) c1 = x;
            else if (x <= c2) c2 = x;
            else return true;
        }
        return false;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}