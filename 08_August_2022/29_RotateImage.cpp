// https://leetcode.com/problems/rotate-image/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // BruteForce:
public:
    int oddevensum(int num)
    {
        int oddSum = 0, evenSum = 0;
        while (num)
        {
            int x = num % 10;
            if (x % 2)
            {
                oddSum += x;
            }
            else
            {
                evenSum += x;
            }
            num /= 10;
        }
        return (oddSum > evenSum ? oddSum : evenSum);
    }

    int SumOfSetBitNumbers(int n, int set)
    {
        vector<char> bin(n, '0');
        int sum = 0;
        solve(bin, sum, set, n - 1);
        return sum;
    }

    void solve(vector<char> &bin, int &sum, int set, int i)
    {
        if (set == 0 || i == -1)
        {
            if (set == 0)
            {
                int num = 0;
                for (int j = 0; j < bin.size(); ++j)
                {
                    num = num * 2 + bin[j] - '0';
                }
                sum += num;
            }
            return;
        }
        bin[i] = '1';
        solve(bin, sum, set - 1, i - 1);
        bin[i] = '0';
        solve(bin, sum, set, i - 1);
    }

    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int a = 0;
        int b = n - 1;
        while (a < b)
        {
            for (int i = 0; i < (b - a); ++i)
            {
                swap(matrix[a][a + i], matrix[a + i][b]);
                swap(matrix[a][a + i], matrix[b][b - i]);
                swap(matrix[a][a + i], matrix[b - i][a]);
            }
            ++a;
            --b;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}