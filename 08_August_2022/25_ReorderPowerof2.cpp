// 

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:

    bool reorderedPowerOf2(int n) {
        long c = counter(n);
        for (int i = 0; i < 32; i++)
            if (counter(1 << i) == c) return true;
        return false;
    }

    long counter(int n) {
        long res = 0;
        for (; n; n /= 10) res += pow(10, n % 10);
        return res;
    }

    int biggest_on_digit_delete(int input1) {
        int Arr[4], minDig = INT_MAX;
        for (int i = 0; i < 4; ++i)
        {
            int x = input1 % 10;
            input1 /= 10;
            Arr[i] = x;
            minDig = min(minDig, x);
        }
        int num = 0;
        for (int i = 3; i >= 0; --i)
        {
            if (Arr[i] == minDig) continue;
            num = num * 10 + Arr[i];
        }
        return num;
    }

    char* left_rotate_string(char *input1, int input2) {
        int len = 0;
        char *res = new char[input2];
        for (int i = 0; input1[i] != '\0'; i++)
        {
            len++;
            if (i < input2) {
                res[i] = input1[i];
            }
        }
        if (input2 > len) return input1;
        char *ans = new char[len];
        int j = 0;
        for (int i = input2; i < len; ++i)
        {
            ans[j] = input1[i];
            ++j;
        }
        int i = 0;
        while (j < len && i < input2) {
            ans[j] = res[i];
            ++j, ++i;
        }
        return ans;        
    }
};

int main () {

    Solution Obj1, obj2;
    Obj1 = obj2 ; 

    int  x = 100, y, z ;
    y = x >> 2 ;
    z = y | 6; 
    cout << z << endl;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}