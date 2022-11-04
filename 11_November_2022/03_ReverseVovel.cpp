// https://leetcode.com/problems/reverse-vowels-of-a-string/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isVovel(char &c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    string reverseVowels(string s)
    {
        int flagi = 1;
        int i = 0, j = s.length()-1;
        while(i < j){
            while(!isVovel(s[i]) && i < j){
                ++i;
            }
            while(!isVovel(s[j]) && i < j){
                --j;
            }
            swap(s[i], s[j]);
            ++i; --j;
        }
        return s;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}