// https://leetcode.com/problems/toeplitz-matrix/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int k = 0; k < matrix.size() - 1; k++)
        {
            // Checking bottom triangle
            int i = k, j = 0;
            int x = matrix[i][j];
            while (i < matrix.size()-1)
            {
                i++;
                j++;
                if (x != matrix[i][j])
                {
                    return false;
                }
            }
        }
        for (int k = 1; k < matrix.size() - 1; k++)
        {
            // Checking upper triangle
            int i = 0, j = k;
            int x = matrix[i][j];
            while (j < matrix[0].size()-1)
            {
                i++;
                j++;
                if (x != matrix[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}