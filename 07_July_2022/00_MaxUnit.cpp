// https://leetcode.com/problems/maximum-units-on-a-truck/

// You are assigned to put some amount of boxes onto one truck. You are
// given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi,
// numberOfUnitsPerBoxi]:

// numberOfBoxesi is the number of boxes of type i.
// numberOfUnitsPerBoxi is the number of units in each box of the type i.
// You are also given an integer truckSize, which is the maximum number
// of boxes that can be put on the truck. You can choose any boxes to put
// on the truck as long as the number of boxes does not exceed truckSize.

// Return the maximum total number of units that can be put on the truck.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        int unit = 0 ;
        sort(boxTypes.begin(), boxTypes.end(), [&](vector<int> &v1, vector<int> &v2)
             { return v1[1] > v2[1]; });
        for(auto it: boxTypes) {
            if (!truckSize)return unit;
            else if (truckSize >= it[0]) unit +=  (it[0] * it[1]), truckSize -= it[0];
            else unit += (truckSize * it[1]), truckSize=0;
        }
        return unit;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}