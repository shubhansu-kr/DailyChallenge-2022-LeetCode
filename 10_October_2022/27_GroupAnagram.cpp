// https://leetcode.com/problems/group-anagrams/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // BruteForce :Sorting
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> temp;
        temp = strs;
        for(auto &it: temp){sort(it.begin(), it.end());}
        unordered_map<string, vector<string>> st;
        for (int i = 0; i < strs.size(); ++i)
        {
            st[temp[i]].emplace_back(strs[i]);
        }
        vector<vector<string>> ans;
        for(auto &it: st){
            ans.emplace_back(it.second);
        }
        return ans;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}