// https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // sort: wa
    // [[7,7],[1,2],[9,7],[7,3],[3,10],[9,8],[8,10],[4,3],[1,5],[1,5]]
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
        {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>> &properties)
    {
        sort(properties.begin(), properties.end(), comp); 
        int mtn = INT_MIN;                                
        int ans = 0;

        for (int i = properties.size() - 1; i >= 0; i--)
        {
            if (properties[i][1] < mtn) 
                ans++;
            mtn = max(mtn, properties[i][1]);
        }
        return ans;
    }
};

class Solution
{
    // sort: wa
    // [[7,7],[1,2],[9,7],[7,3],[3,10],[9,8],[8,10],[4,3],[1,5],[1,5]]
public:
    int numberOfWeakCharacters(vector<vector<int>> &properties)
    {
        sort(properties.begin(), properties.end(), [](vector<int> &v1, vector<int> &v2)
             { return v1[0] > v2[0]; });

        int count = 0;
        for (int i = 0; i < properties.size(); ++i)
        {
            for (int j = i + 1; j < properties.size(); ++j)
            {
                if (properties[i][0] > properties[j][0] && properties[i][1] > properties[j][1])
                {
                    ++count;
                    break;
                }
            }
        }
        return count;
    }
};

class Solution
{
    // BruteForce : TLE
public:
    int numberOfWeakCharacters(vector<vector<int>> &properties)
    {
        int count = 0;
        for (int i = 0; i < properties.size(); ++i)
        {
            for (int j = 0; j < properties.size(); ++j)
            {
                if (j == i)
                    continue;
                if (properties[i][0] > properties[j][0] && properties[i][1] > properties[j][1])
                {
                    ++count;
                    break;
                }
            }
        }
        return count;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}