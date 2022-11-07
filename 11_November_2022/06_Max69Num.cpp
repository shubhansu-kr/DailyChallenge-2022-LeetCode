// https://leetcode.com/problems/maximum-69-number/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int maximum69Number (int num) {
        string nums = to_string(num);
        for (auto &it: nums){
            if (it == '6') {
                it = '9';
                break;
            }
        }
        return stoi(nums);
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}