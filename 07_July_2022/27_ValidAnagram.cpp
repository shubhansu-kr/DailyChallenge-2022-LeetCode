// https://leetcode.com/problems/valid-anagram/

#include <bits/stdc++.h>
using namespace std ;

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