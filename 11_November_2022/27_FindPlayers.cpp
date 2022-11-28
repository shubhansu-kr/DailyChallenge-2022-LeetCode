// https://leetcode.com/problems/find-players-with-zero-or-one-losses/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        vector<vector<int>> res(2);
        unordered_map<int, int> mp;
        set<int> s;
        for (int i = 0; i < matches.size(); i++)
        {
            mp[matches[i][1]]++;
            s.insert(matches[i][0]);
            s.insert(matches[i][1]);
        }
        for (auto it : s)
        {
            if (mp.find(it) != mp.end())
            {
                if (mp[it] == 1)
                    res[1].push_back(it);
            }
            else
                res[0].push_back(it);
        }
        return res;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}