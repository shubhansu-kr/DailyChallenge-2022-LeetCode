// https://leetcode.com/problems/reverse-words-in-a-string/submissions/842681770/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    string reverseWords(string s) {
        string ans;
        stack<string> p;
        int sw = 0;
        for (char a : s)
        {
            if (sw)
            {
                if (a != ' ')
                {
                    ans.push_back(a);
                }
                else
                {
                    p.push(ans);
                    ans.clear();
                    sw = 0;
                }
            }
            else
            {
                if (a != ' ')
                {
                    ans.push_back(a);
                    sw = 1;
                }
            }
        }
        if (ans.length())
        {
            ans.push_back(' ');
        }
        while (!p.empty())
        {
            ans.append(p.top());
            ans.push_back(' ');
            p.pop();
        }
        ans.pop_back();

        return ans;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}