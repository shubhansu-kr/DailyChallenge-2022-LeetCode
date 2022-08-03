// https://leetcode.com/problems/my-calendar-i/

#include <bits/stdc++.h>
using namespace std ;

class MyCalendar {
public:
    map<int,int>events;
    MyCalendar() {   
    }
    bool book(int start, int end) {
        auto next = events.upper_bound(start);
        if(next != events.end() &&   (*next).second < end)return false;
        events.insert({end,start});
        return true;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}