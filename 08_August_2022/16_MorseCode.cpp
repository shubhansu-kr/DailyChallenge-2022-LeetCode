// https://leetcode.com/problems/unique-morse-code-words/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> p = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        unordered_set<string> t;
        for (int i = 0; i < words.size(); i++)
        {
            string code;
            for (int j = 0; j < words[i].length(); j++)
            {
                code.append(p[(words[i][j] - 97)]);
            }
            t.insert(code);
        }
        return t.size();
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}