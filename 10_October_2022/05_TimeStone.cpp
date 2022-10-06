// https://leetcode.com/problems/time-based-key-value-store/

#include <bits/stdc++.h>
using namespace std;

class TimeMap
{
public: 
    unordered_map<string, map<int, string>> m;
    void set(string key, string value, int timestamp)
    {
        m[key].insert({timestamp, value});
    }
    string get(string key, int timestamp)
    {
        auto it = m[key].upper_bound(timestamp);
        return it == m[key].begin() ? "" : prev(it)->second;
    }
};

class TimeMap
{
    // TLE
    unordered_map<string, unordered_map<int, string>> mp;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
        mp[key][timestamp] = value;
    }

    string get(string key, int timestamp)
    {
        int k = INT_MIN;
        for (auto &it : mp[key])
        {
            if (it.first <= timestamp)
            {
                k = max(k, it.first);
            }
        }
        return mp[key][k];
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}