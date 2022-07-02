// https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

// You are given a rectangular cake of size h x w and two arrays of
// integers horizontalCuts and verticalCuts where:

// horizontalCuts[i] is the distance from the top of the rectangular
// cake to the ith horizontal cut and similarly, and
// verticalCuts[j] is the distance from the left of the rectangular
// cake to the jth vertical cut.
// Return the maximum area of a piece of cake after you cut at each
// horizontal and vertical position provided in the arrays horizontalCuts
// and verticalCuts. Since the answer can be a large number, return
// this modulo 109 + 7.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Brute force
public:
    int maxArea(int h, int w, vector<int> &horizontalCuts, vector<int> &verticalCuts)
    {
        // Cuts are not sorted 
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int mod = pow(10, 9) + 7;
        int prev = 0, maxH = INT_MIN, maxV = INT_MIN;
        for (int &it : horizontalCuts)
            maxH = max(maxH, (it - prev)), prev = it;
        maxH = max(maxH, (h - prev));
        prev = 0;
        for (int &it : verticalCuts)
            maxV = max(maxV, (it - prev)), prev = it;
        maxV = max(maxV, (w - prev));

        return (long) (maxH * maxV) % mod;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}