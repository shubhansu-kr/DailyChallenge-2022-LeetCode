// https://leetcode.com/problems/first-unique-character-in-a-string/

// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> p;
        for(auto &a: s) p[a]++;
        for (int i = 0; i < s.length(); ++i)
        {
            if(p[s[i]] == 1) return i;
        }
        return -1;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}