// https://leetcode.com/problems/satisfiability-of-equality-equations/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int uf[26];
    bool equationsPossible(vector<string>& equations) {
        for (int i = 0; i < 26; ++i) uf[i] = i;
        for (string &e : equations) if (e[1] == '=') uf[find(e[0] - 'a')] = find(e[3] - 'a');
        for (string &e : equations) if (e[1] == '!' && find(e[0] - 'a') == find(e[3] - 'a')) return false;
        return true;
    }

    int find(int x) {
        if (x != uf[x]) uf[x] = find(uf[x]);
        return uf[x];
    }
};

class Solution {
    // WA 
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> trce(26, 0);
        int fill = 1;
        for(auto &it: equations) {
            if(trce[it[0]-'a']){
                if (it[1] == '=') {
                    if (trce[it[3]-'a']) {
                        
                    }
                    else {
                        trce[it[3]-'a'] = trce[it[0]-'a'];
                    }
                }
                else {

                }
            }
            else {
                if (it[1] == '=') {
                    if (trce[it[3]-'a']) {
                        trce[it[0]-'a'] = trce[it[3]-'a'];
                    }
                    else {
                        trce[it[0]-'a'] = fill;
                        trce[it[3]-'a'] = fill++;
                    }
                }
                else {
                    if (trce[it[3]-'a']) {
                        trce[it[0]-'a'] = fill++;
                    }
                    else {
                        trce[it[3]-'a'] = fill++;
                        trce[it[0]-'a'] = fill++;
                    }
                }
            }
        }
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}