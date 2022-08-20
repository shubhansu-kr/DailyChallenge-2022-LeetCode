// https://leetcode.com/problems/minimum-number-of-refueling-stops/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        long dp[501] = {startFuel};
        for (int i = 0; i < stations.size(); ++i)
            for (int t = i; t >= 0 && dp[t] >= stations[i][0]; --t)
                dp[t + 1] = max(dp[t + 1], dp[t] + stations[i][1]);
        for (int t = 0; t <= stations.size(); ++t)
            if (dp[t] >= target) return t;
        return -1;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}