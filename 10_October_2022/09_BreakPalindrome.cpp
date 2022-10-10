// https://leetcode.com/problems/break-a-palindrome/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.length();
        if (n == 1) {return "";}
        for (int i = 0; i < n/2; ++i)
        {
            if (palindrome[n-i-1] != 'a') {
                palindrome[i] = 'a';
                return palindrome;
            }
        }
        palindrome[n-1] = 'b';
        return palindrome;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}