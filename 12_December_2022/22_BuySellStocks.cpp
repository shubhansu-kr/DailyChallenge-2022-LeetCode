// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> A(2, 0), B(2, 0), C(2, 0);
        for (int i = n-1; i >= 0; --i)
        {
            for (int stock = 0; stock < 2; ++stock)
            {
                int action = 0, noAction = B[stock];
                if (stock) action = C[0] + prices[i];
                else action = B[1] - prices[i];
                A[stock] = max(action, noAction);
            }
            C = B, B = A;
        }
        
        return A[0];
    }
};

int main () {
    
    return 0;
}