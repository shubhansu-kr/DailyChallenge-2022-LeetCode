// https://leetcode.com/problems/minimum-genetic-mutation/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minMutation(string start, string end, vector<string> &bank)
    {
        unordered_set<string> st{bank.begin(), bank.end()};
        if (!st.count(end)) return -1;
        queue<string> que;
        que.push(start);
        int steps = 0, s;
        string cur, t;
        while (!que.empty())
        {
            s = que.size();
            while (s--)
            {
                cur = que.front();
                que.pop();
                if (cur == end) return steps;
                st.erase(cur);
                for (int i = 0; i < 8; i++)
                {
                    t = cur;
                    t[i] = 'A';
                    if (st.count(t)) que.push(t);
                    t[i] = 'C';
                    if (st.count(t)) que.push(t);
                    t[i] = 'G';
                    if (st.count(t)) que.push(t);
                    t[i] = 'T';
                    if (st.count(t)) que.push(t);
                }
            }
            steps++;
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