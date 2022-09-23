// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int concatenatedBinary(int n) {
        long ans = 0, MOD = 1e9 + 7, len = 0;
        for (int i = 1; i <= n; ++i) {
            if(__builtin_popcount(i) == 1) ++len;
            ans = ((ans << len) % MOD + i) % MOD;
        }
        return ans;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}