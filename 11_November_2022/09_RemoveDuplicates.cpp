// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    string removeDuplicates(string s) {
        // let's use stack
        stack<char> st;
        int i = 0;
        while(i < s.length()){
            if (!st.empty() && st.top() == s[i]){st.pop();}
            else {st.push(s[i]);}
            ++i;
        }
        string res;
        while(st.size()){res += st.top();st.pop();}
        reverse(res.begin(), res.end());
        return res;
    }
};

class Solution1 {
public:
    // TLE
    string removeDuplicates(string s) {
        int flag = 1; 
        while(flag) {
            flag = 0;
            for (int i = 1; i < s.length(); ++i)
            {
                if (s[i] == s[i-1]){
                    s.erase(i-1, 2);
                    flag = 1;
                    break;
                }
            }
        }
        return s;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}