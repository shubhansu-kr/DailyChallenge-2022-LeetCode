// https://leetcode.com/problems/sort-characters-by-frequency/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    //  BruteForce: Use Map 
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        vector<string> bucket(s.size()+1, "");
        string res;
        
        for(char c:s) freq[c]++;
        for(auto& it:freq) {
            int n = it.second;
            char c = it.first;
            bucket[n].append(n, c);
        }
        for(int i=s.size(); i>0; i--) {
            if(!bucket[i].empty()) res.append(bucket[i]);
        }
        return res;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}