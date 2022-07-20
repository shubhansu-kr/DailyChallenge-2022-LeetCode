// https://leetcode.com/problems/number-of-matching-subsequences/

// Given a string s and an array of strings words, return the number 
// of words[i] that is a subsequence of s.
// A subsequence of a string is a new string generated from the original 
// string with some characters (can be none) deleted without changing 
// the relative order of the remaining characters.
// For example, "ace" is a subsequence of "abcde"

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<const char*> waiting[128];
    for (auto &w : words)
        waiting[w[0]].push_back(w.c_str());
    for (char c : s) {
        auto advance = waiting[c];
        waiting[c].clear();
        for (auto it : advance)
            waiting[*++it].push_back(it);
    }
    return waiting[0].size();
    }
};

class Solution {
    // BruteForce: TLE
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_set<string> track;
        string temp = "";

        subSeq(s, track, temp);

        int ans = 0;
        for(auto &it: words) {if (track.count(it)) ans++;}
        return ans;
    }
    void subSeq(string &s, unordered_set<string> &track, string &temp, int i = 0) {
        if (i == s.size()) {
            track.insert(temp);
            return ;
        }

        temp += s[i] ;
        subSeq(s, track, temp, i+1);
        temp.pop_back();
        subSeq(s, track, temp, i+1);
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}