// https://leetcode.com/problems/find-k-closest-elements/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Calculate the diff 
        unordered_map<int, int> m;
        int temp;
        for (int i = 0; i < arr.size(); ++i)
        {
            temp = abs(arr[i]-x);
            if (arr[i] < x){
                m[temp]++;
            }
            arr[i] = temp;
        }
        sort(arr.begin(), arr.end());
        vector<int> ans;
        
        for (int i = 0; i < k; ++i)
        {
            if (m[arr[i]]){
                ans.emplace_back(x - arr[i]);
                --m[arr[i]];
            } 
            else ans.emplace_back(x + arr[i]);
        }
        return ans;
    }
};

class Solution {
    // WA: The integer x may not be a part of the array. 
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        arr.insert(arr.begin(), INT_MAX);
        arr.emplace_back(INT_MAX);
        vector<int> ans;
        for (int i = 0; i < arr.size(); ++i)
        {
            if (arr[i] == x) {
                int p = i - 1, q = i + 1;
                while(k--) {
                    if (abs(arr[i] - arr[q]) < abs(arr[i]-arr[p])){
                        ans.emplace_back(arr[q++]);
                    }
                    else {
                        ans.emplace_back(arr[p--]);
                    }
                }
                break;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}