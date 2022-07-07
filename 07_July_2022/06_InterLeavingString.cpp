// https://leetcode.com/problems/interleaving-string/

// Given strings s1, s2, and s3, find whether s3 is formed by an
// interleaving of s1 and s2.
// An interleaving of two strings s and t is a configuration where they
// are divided into non-empty substrings such that:
// s = s1 + s2 + ... + sn
// t = t1 + t2 + ... + tm
// |n - m| <= 1
// The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 +
// s2 + t3 + s3 + ...
// Note: a + b is the concatenation of strings a and b.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // BruteForce
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s3.length() != s1.length() + s2.length())
            return false;
        bool dp[s1.length() + 1][s2.length() + 1];

        for (int i = 0; i < s1.length() + 1; i++)
            for (int j = 0; j < s2.length() + 1; j++)
            {
                if (i == 0 && j == 0)
                    dp[i][j] = true;
                else if (i == 0)
                    dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
                else if (j == 0)
                    dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]);
                else
                    dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }

        return dp[s1.length()][s2.length()];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}