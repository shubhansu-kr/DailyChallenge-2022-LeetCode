// https://leetcode.com/problems/unique-number-of-occurrences/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        set<int> value;
        set<int> elementCount;
        for (int i = 0; i < arr.size(); i++)
        {
            if (!value.count(arr[i]))
            {
                value.insert(arr[i]);
                int count = 0;
                for (int j = 0; j < arr.size(); j++)
                {
                    if (arr[i] == arr[j])
                    {
                        count++;
                    }
                }
                if (!elementCount.count(count))
                {
                    elementCount.insert(count);
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}