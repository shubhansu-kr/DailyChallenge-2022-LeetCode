// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // BruteForce Recursion
public:
    int maxLength(vector<string>& arr) {
        unordered_set<char> freq;
        return solve(arr, freq, arr.size()-1);
    }

    int solve(vector<string> &arr, unordered_set<char>& freq, int i){
        if (i == -1){return 0;}
        unordered_set<char> temp = freq;
        int pick = -1e9, noPick, flag = 1;
        for(auto &it: arr[i]){
            if (temp.count(it)){flag = 0;break;}
            else {temp.insert(it);}
        }
        if (flag){pick = arr[i].size() + solve(arr, temp, i-1);}

        noPick = solve(arr, freq, i-1);
        return max(pick, noPick);
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}