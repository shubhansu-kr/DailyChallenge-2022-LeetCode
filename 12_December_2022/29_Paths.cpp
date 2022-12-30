// https://leetcode.com/problems/all-paths-from-source-to-target/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int>> &graph, vector<vector<int>> &res, vector<int> &path, int cur)
    {
        path.push_back(cur);
        if (cur == graph.size() - 1)
            res.push_back(path);
        else
            for (auto it : graph[cur])
                dfs(graph, res, path, it);
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(graph, paths, path, 0);
        return paths;
    }
};

int main()
{

    return 0;
}