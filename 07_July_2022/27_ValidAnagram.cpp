// https://leetcode.com/problems/valid-anagram/

#include <bits/stdc++.h>
using namespace std ;

class Solution1 
{
    // Using unordered_map
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> ana;
        for(auto &a: s) ++ana[a];
        for(auto &a: t) if(ana[a])--ana[a];else return false;
        return true;      
    }
};

class Solution 
{
    // BruteForce: Using vector
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        vector<int> anagram(26, 0);
        for (int i = 0; i < s.length(); ++i) ++anagram[s[i]-'a'];
        for (int i = 0; i < t.length(); ++i)
        {
            if(anagram[t[i]-'a'])--anagram[t[i]-'a'];
            else return false;
        }
        return true;        
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}