// https://leetcode.com/problems/orderly-queue/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string orderlyQueue(string s, int k)
    {
        if (k > 1)
        {
            sort(s.begin(), s.end());
            return s;
        }
        else
        {
            string temp = s;
            s += s;
            for (int i = 1; i < temp.length(); i++)
            {
                temp = min(temp, s.substr(i, temp.size()));
            }
            return temp;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}