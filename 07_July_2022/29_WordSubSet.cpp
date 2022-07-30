// https://leetcode.com/problems/word-subsets/

// You are given two string arrays words1 and words2.
// A string b is a subset of string a if every letter in b occurs
// in a including multiplicity.
// For example, "wrr" is a subset of "warrior" but is not a
// subset of "world".
// A string a from words1 is universal if for every string b
// in words2, b is a subset of a.
// Return an array of all the universal strings in words1. You
// may return the answer in any order.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // BruteForce : Iterative: Wrong Answer
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<string> ans;
        for (int i = 0; i < words1.size(); ++i)
        {
            int flag = 1;
            for (int j = 0; j < words2.size(); ++j)
            {
                if (!checkSubset(words1[i], words2[j]))
                {
                    flag = 0;
                    break;
                }
            }
            if (flag){ans.emplace_back(words1[i]);}
        }
        return ans;
    }

    // Check if t is a subset of s
    bool checkSubset(string &s, string &t)
    {
        if (s.size() < t.size()) return false;
        int i = s.size()-1, j = t.size()-1;

        while (true){
            if (j == -1) return true;
            if (i == -1) return false;
            if (s[i] == t[j]) --i, --j;
            else --i;
        }
        return false;
    }

};

class Solution
{
    // BruteForce :Recursion
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        vector<string> ans;
        for (int i = 0; i < words1.size(); ++i)
        {
            int flag = 1;
            for (int j = 0; j < words2.size(); ++j)
            {
                if (!checkSubset(words1[i], words2[j]))
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                ans.emplace_back(words1[i]);
            }
        }
        return ans;
    }

    // Check if t is a subset of s
    bool checkSubset(string &s, string &t)
    {
        if (s.size() < t.size())
            return false;
        int m = s.size(), n = t.size();
        return solve(s, t, m - 1, n - 1);
    }

    bool solve(string &s, string &t, int i, int j)
    {
        if (j == -1)
            return true;
        if (i == -1)
            return false;

        // Match
        if (s[i] == t[j])
            return solve(s, t, i - 1, j - 1);
        // No match
        return solve(s, t, i - 1, j);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}