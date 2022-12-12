// https://leetcode.com/problems/climbing-stairs/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // BruteForce : Recursion 
public:
    int climbStairs(int n) {
        if (n <= 0) return n == 0;
        return climbStairs(n-1) + climbStairs(n-2);
    }
};

int main () {
    
    return 0;
}