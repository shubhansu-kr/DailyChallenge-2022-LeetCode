// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

// Given an n x n matrix where each of the rows and columns is 
// sorted in ascending order, return the kth smallest element 
// in the matrix.
// Note that it is the kth smallest element in the sorted order, 
// not the kth distinct element.
// You must find a solution with a memory complexity better than O(n2).

#include <bits/stdc++.h>
using namespace std ;

class Solution2 {
    // Using queue: Wrong solution 
public:
    int m, n;
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        m = matrix.size(), n = matrix[0].size(); // For general, the matrix need not be a square
        int left = matrix[0][0], right = matrix[m-1][n-1], ans = -1;
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (countLessOrEqual(matrix, mid) >= k) {
                ans = mid;
                right = mid - 1; // try to looking for a smaller value in the left side
            } else left = mid + 1; // try to looking for a bigger value in the right side
        }
        return ans;
    }
    int countLessOrEqual(vector<vector<int>>& matrix, int x) {
        int cnt = 0, c = n - 1; // start with the rightmost column
        for (int r = 0; r < m; ++r) {
            while (c >= 0 && matrix[r][c] > x) --c;  // decrease column until matrix[r][c] <= x
            cnt += (c + 1);
        }
        return cnt;
    }
};

class Solution1 {
    // Using queue: Wrong solution 
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        stack<int> num, temp; 
        for(auto &a: matrix)
            for(auto &b: a){
                while(num.size() && num.top() > k) {
                    temp.push(num.top());
                    num.pop();
                }
                num.push(k);
                while (temp.size() && num.size() < k) {
                    num.push(temp.top());
                    temp.pop();
                }
            }
        return num.top();        
    }
};

class Solution {
    // BruteForce: Using sets 
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        set<int> track; 
        for(auto &a: matrix)
            for(auto &b: a) {
                if (track.count(b)) {
                    --k;
                }
                else {
                    track.insert(b);
                }
            }
        for (auto a: track) {
            if (k == 0) {
                return a;
            }
            --k;
        }
        return -1;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}