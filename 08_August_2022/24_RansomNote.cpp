// https://leetcode.com/problems/ransom-note/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> m;
        for(auto &a: ransomNote) {
            m[a]++;
        }
        for(auto &a: magazine){
            m[a]--;
        }
        for(auto &a: m) {
            if (a.second > 0) return false;
        }
        return true;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}