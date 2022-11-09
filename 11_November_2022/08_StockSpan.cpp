// https://leetcode.com/problems/online-stock-span/

#include <bits/stdc++.h>
using namespace std ;

class StockSpanner {
public:
    StockSpanner() {}
    stack<pair<int, int>> stak;
    int next(int price) {
        int span = 1;
        while (!stak.empty() && stak.top().second <= price) {
            span= span+ stak.top().first;
            stak.pop();
        }
        stak.push({span,price});
        return span;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}