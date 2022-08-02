// https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

// Given an n x n matrix where each of the rows and columns is 
// sorted in ascending order, return the kth smallest element 
// in the matrix.
// Note that it is the kth smallest element in the sorted order, 
// not the kth distinct element.
// You must find a solution with a memory complexity better than O(n2).

#include <bits/stdc++.h>
using namespace std ;

class Solution1 {
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