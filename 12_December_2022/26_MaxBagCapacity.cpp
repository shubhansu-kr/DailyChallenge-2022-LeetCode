// https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        vector<int> count;
        int n = rocks.size(), i;
        for (int i = 0; i < n; ++i)
            count.push_back(capacity[i] - rocks[i]);
        sort(count.begin(), count.end());
        for (i = 0; i < n && additionalRocks >= count[i]; ++i)
            additionalRocks -= count[i];
        return i;
    }
};

int main()
{

    return 0;
}