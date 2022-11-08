// https://leetcode.com/problems/make-the-string-great/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    string makeGood(string s) {
        int flag = 1;
        while(flag){
            flag = 0;
            for (int i = 1; i < s.length(); ++i)
            {
                if (s[i] >= 'a' && s[i] <= 'z'){
                    // s[i] is lowercase letter
                    if (s[i-1] == s[i]-32){
                        s.erase(i-1, 2);
                        flag = 1;
                        break;
                    }
                }
                else {
                    // uppercase letter
                    if (s[i-1] == s[i]+32){
                        s.erase(i-1, 2);
                        flag = 1;
                        break;
                    }
                }
            }
        }
        return s;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Solution Obj1;
    // cout << Obj1.makeGood("abBAcC");
    
    string s = "abcd";
    s.erase(1, 2);
    cout << s ;

    return 0;
}