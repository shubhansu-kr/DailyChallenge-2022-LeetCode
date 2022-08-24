// https://leetcode.com/problems/power-of-three/submissions/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool isPowerOfThree(int n) {
        return n>0 && 1162261467 % n == 0 ;
    }

    int sumOfSeries (int N) {
        int result = 0;
        int x = 3; 
        while (x < N) {
            result += (N/x);
            x *= 3 ;
        }   
        return result;
    }

    int grocerySale(int N, int A[]) {
        int totalCost = 0, discount = 0;

        vector<int> arr(N, 0);
        for (int i = 0; i < N; ++i)
        {
            totalCost += A[i];
            arr[i] = A[i];
        }
        if (N < 4) return totalCost;
        sort(arr.begin(), arr.end(), greater<int>());
        for (int i = 1; i < N; ++i)
        {
            if ((i+1) % 4 == 0) {
                discount += arr[i];
            } 
        }
        
        return totalCost - discount;
    }
};

int main () {
    int A[] = {3, 6, 2, 5, 1};
    int N = 5;

    Solution Obj1; 
    cout << Obj1.grocerySale(N, A);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}