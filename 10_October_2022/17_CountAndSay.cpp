// https://leetcode.com/problems/count-and-say/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    string say(string s){
        string ans = "";
        int count = 1, i = 1;
        for (i = 1; i < s.length(); ++i)
        {
            if (s[i] == s[i-1]){++count;}
            else{
                ans.push_back('0'+count);
                ans.push_back(s[i-1]);
                count = 1;
            }
        }
        ans.push_back('0'+count);
        ans.push_back(s[i-1]);
        return ans;
    }
    string countAndSay(int n) {
        if (n == 1) return "1";
        return say(countAndSay(n-1));
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}