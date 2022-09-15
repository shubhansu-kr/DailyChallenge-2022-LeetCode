// https://leetcode.com/problems/find-original-array-from-doubled-array/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // Wrong Answer 
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        if (changed.size() % 2) return {};
        unordered_map<int, int> c;
        for (int a : changed) c[a]++;
        vector<int> keys;
        for (auto it : c) keys.push_back(it.first);
        sort(keys.begin(), keys.end(), [](int i, int j) {return abs(i) < abs(j);});
        vector<int> res;
        for (int x : keys) {
            if (c[x] > c[2 * x]) return {};
            for (int i = 0; i < c[x]; ++i, c[2 * x]--) res.push_back(x);
        }
        return res;
    }
};

class Solution {
    // Wrong Answer 
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2) return vector<int>();
        map<int, int> freq;
        for(auto &a: changed){
            freq[a]++;
        }
        n /= 2;
        vector<int> ans;
        for(auto &a: freq) {
            if (n--) break;
            if (!a.second){continue;}
            if(freq[a.first*2]){
                ans.emplace_back(a.first);
                freq[a.first*2]--;
            }
            else {
                return vector<int>();
            }
        }
        return ans;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}