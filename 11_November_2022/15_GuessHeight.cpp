// https://leetcode.com/problems/guess-number-higher-or-lower/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int guessNumber(int n) {
        int maxNumber = n, minNumber = 1;
        while (true) {
            int meanNumber = (maxNumber - minNumber) / 2 + minNumber;
            int res = guess(meanNumber);
            if (res == 0) { 
                return meanNumber;
            } else if (res == 1) {
                minNumber = meanNumber + 1;
            } else {
                maxNumber = meanNumber - 1;
            }
        }
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}