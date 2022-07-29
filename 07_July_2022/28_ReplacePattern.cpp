// https://leetcode.com/problems/find-and-replace-pattern/

// Given a list of strings words and a string pattern, return a list 
// of words[i] that match pattern. You may return the answer in any order.
// A word matches the pattern if there exists a permutation of letters 
// p so that after replacing every letter x in the pattern with p(x), 
// we get the desired word.
// Recall that a permutation of letters is a bijection from letters 
// to letters: every letter maps to another letter, and no two letters 
// map to the same letter.

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        if (pattern.length() == 1) return words;
        vector<string> ans;
        for(string &s: words) {
            // check for each word and validate the pattern 
            unordered_map<char, char> m;
            unordered_set<char> us; 
            int flag = 1 ;
            for (int i = 0; i < s.length(); ++i)
            {
                if(us.count(s[i])) {
                    if (m[s[i]] == pattern[i]) {
                        continue;
                    }
                    else {
                        flag = 0 ;
                        break;
                    }
                }
                else {
                    us.insert(s[i]);
                    m[s[i]] = pattern[i];
                }
            }
            if (flag) {
                ans.emplace_back(s);
            }
        }
        return ans; 
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}