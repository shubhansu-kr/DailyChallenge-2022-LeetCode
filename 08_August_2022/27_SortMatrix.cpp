// https://leetcode.com/problems/sort-the-matrix-diagonally/

#include <bits/stdc++.h>
using namespace std ;

class Solution1 {
    // priority Queue
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        // all elements on same diagonal have same i-j result.
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> map; // min priority queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                map[i - j].push(mat[i][j]);
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = map[i - j].top(); map[i - j].pop();
            }
        }
        return mat;
    }
};

class Solution {
    // BruteForce: 
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < n; ++i)
        {
            int row = 0, col = i;
            vector<int> temp;
            while (row < m && col < n) {
                temp.emplace_back(mat[row][col]);
                ++row, ++col;
            }
            sort(temp.begin(), temp.end());
            row = 0, col = i;
            int k = 0;
            while (row < m && col < n) {
                mat[row][col] = temp[k];
                ++row, ++col, ++k;
            }
        }
        for (int i = 1; i < m; ++i)
        {
            int row = i, col = 0;
            vector<int> temp;
            while (row < m && col < n) {
                temp.emplace_back(mat[row][col]);
                ++row, ++col;
            }
            sort(temp.begin(), temp.end());
            row = i, col = 0;
            int k = 0;
            while (row < m && col < n) {
                mat[row][col] = temp[k];
                ++row, ++col, ++k;
            }
        }
        return mat;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}