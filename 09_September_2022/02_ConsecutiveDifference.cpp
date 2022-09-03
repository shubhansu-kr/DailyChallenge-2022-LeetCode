// https://leetcode.com/problems/numbers-with-same-consecutive-differences/

// Return all non-negative integers of length n such that the absolute
// difference between every two consecutive digits is k.
// Note that every number in the answer must not have leading zeros.
// For example, 01 has one leading zero and is invalid.
// You may return the answer in any order.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int num, int n, int k, vector<int> &res)
    {
        if (n == 0) res.push_back(num);
        else
        {
            int dig = num % 10;
            if (dig + k <= 9) dfs(num * 10 + dig + k, n - 1, k, res);
            if (k != 0 && dig >= k) dfs(num * 10 + dig - k, n - 1, k, res);
        }
    }
    vector<int> numsSameConsecDiff(int n, int k)
    {
        vector<int> res;
        for (auto num = 1; num <= 9; ++num) dfs(num, n - 1, k, res);
        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}