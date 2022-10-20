// https://leetcode.com/problems/integer-to-roman/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        vector<string> mp = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X","IX", "V", "IV", "I"};
        while(num) {
            if (num >= 1000) {ans += mp[0]; num -= 1000;}
            else if (num >= 900) {ans += mp[1]; num -= 900;}
            else if (num >= 500) {ans += mp[2]; num -= 500;}
            else if (num >= 400) {ans += mp[3]; num -= 400;}
            else if (num >= 100) {ans += mp[4]; num -= 100;}
            else if (num >= 90) {ans += mp[5]; num -= 90;}
            else if (num >= 50) {ans += mp[6]; num -= 50;}
            else if (num >= 40) {ans += mp[7]; num -= 40;}
            else if (num >= 10) {ans += mp[8]; num -= 10;}
            else if (num >= 9) {ans += mp[9]; num -= 9;}
            else if (num >= 5) {ans += mp[10]; num -= 5;}
            else if (num >= 4) {ans += mp[11]; num -= 4;}
            else if (num >= 1) {ans += mp[12]; num -= 1;}
        }
        return ans;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}