// https://leetcode.com/problems/check-if-the-sentence-is-pangram/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> pan(26, 0);
        for(auto &it: sentence) pan[it - 'a']++; 
        for(auto &it: pan) if (!it) return false;
        return true;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution S1;
    cout << S1.checkIfPangram("thequickbrownfoxjumpsoverthelazydog");
    return 0;
}