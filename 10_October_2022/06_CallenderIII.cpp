// https://leetcode.com/problems/my-calendar-iii/

#include <bits/stdc++.h>
using namespace std ;

class MyCalendarThree {
    map<int, int> timeline;
public:
    int book(int start, int end) {
        timeline[start]++; 
        timeline[end]--;
        int ongoing = 0, k = 0;
        for (pair<int, int> t : timeline)
            k = max(k, ongoing += t.second);
        return k;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}