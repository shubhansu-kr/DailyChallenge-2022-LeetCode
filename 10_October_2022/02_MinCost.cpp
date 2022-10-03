// https://leetcode.com/problems/minimum-time-to-make-rope-colorful/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cost = 0;
        for (int i = 1; i < colors.size(); ++i)
        {
            if (colors[i] == colors[i-1]) {
                int temp;
                if (neededTime[i] < neededTime[i-1]) {
                    temp = neededTime[i];
                    neededTime[i] = neededTime[i-1];
                }
                else {
                    temp = neededTime[i-1];
                }
                cost += temp;
            }
        }
        return cost;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}