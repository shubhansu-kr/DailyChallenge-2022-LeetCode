// https://leetcode.com/problems/valid-anagram/

#include <bits/stdc++.h>
using namespace std ;

class Solution3
{
    // Using Maths
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        unsigned int sum_s = 1, sum_t = 1;
        for (int i = 0; i < s.length(); ++i)
        {
            sum_s += s[i] * ((s[i] + 1) / 2);
            sum_t += t[i] * ((t[i] + 1) / 2);
        }
        return sum_s == sum_t;
    }
};

class Solution2 
{
    // Sorting
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t; 
    }
};
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