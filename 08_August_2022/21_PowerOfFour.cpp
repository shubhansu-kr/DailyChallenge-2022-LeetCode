// https://leetcode.com/problems/power-of-four/submissions/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        return (n > 0 && !(n & (n - 1)) && (n - 1) % 3 == 0);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}