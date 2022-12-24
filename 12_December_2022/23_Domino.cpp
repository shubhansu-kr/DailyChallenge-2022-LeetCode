// https://leetcode.com/problems/domino-and-tromino-tiling/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numTilings(int N)
    {
        long long g[1001], u[1001];
        int mod = 1000000007;
        g[0] = u[0] = 0;
        g[1] = u[1] = 1;
        g[2] = u[2] = 2;

        for (int i = 3; i <= N; i++)
        {
            u[i] = (u[i - 1] + g[i - 1]) % mod;
            g[i] = (g[i - 1] + g[i - 2] + 2 * u[i - 2]) % mod;
        }
        return g[N] % mod;
    }
};

int main()
{

    return 0;
}