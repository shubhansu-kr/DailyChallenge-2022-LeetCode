// https://leetcode.com/problems/single-threaded-cpu/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        vector<int> res, idx(tasks.size());
        priority_queue<pair<int, int>> pq;
        iota(begin(idx), end(idx), 0);
        sort(begin(idx), end(idx), [&](int i, int j)
             { return tasks[i][0] < tasks[j][0]; });
        for (long i = 0, time = 1; i < idx.size() || !pq.empty();)
        {
            for (; i < idx.size() && tasks[idx[i]][0] <= time; ++i)
                pq.push({-tasks[idx[i]][1], -idx[i]});
            if (!pq.empty())
            {
                auto [procTime, j] = pq.top();
                pq.pop();
                time -= procTime;
                res.push_back(-j);
            }
            else
                time = tasks[idx[i]][0];
        }
        return res;
    }
};

int main()
{

    return 0;
}