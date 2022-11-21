// https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
    {
        int n = maze.size();
        int m = maze[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;
        vis[entrance[0]][entrance[1]] = 1;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        q.push({{entrance[0], entrance[1]}, 0});
        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            cout << t << endl;

            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int nr = dr[i] + r;
                int nc = dc[i] + c;
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] != 1 && maze[nr][nc] == '.')
                {

                    q.push({{nr, nc}, t + 1});
                    vis[nr][nc] = 1;

                    cout << nr << nc << q.front().second << endl;
                    ;
                    if (nr == 0 || nc == 0 || nr == (n - 1) || nc == (m - 1))
                        return t + 1;
                }
            }
        }
        return -1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}