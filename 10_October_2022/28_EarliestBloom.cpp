// https://leetcode.com/problems/earliest-possible-day-of-full-bloom/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int, int>> times(n);
        for (int i = 0; i < n; i++) {
            times[i].first = -growTime[i];
            times[i].second = plantTime[i];
        }
        sort(times.begin(), times.end());
        int tot = 0;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            tot = max(tot, cur + times[i].second - times[i].first);
            cur += times[i].second;
        }
        return tot;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}