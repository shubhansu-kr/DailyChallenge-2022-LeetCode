// Find max XOR

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:

    long countMoves (long A, int B) {
        // Write your code here 
        vector<int> nums ;
        long temp = A; 
        while (temp) {
            nums.emplace_back(temp%10);
            temp /= 10;
        }
        reverse(nums.begin(), nums.end());
        long sum = 0, num = 0, subhand = 1, flag = -1, x;
        for (int i = 0; i < nums.size(); ++i)
        {
            sum+= nums[i];
            if (sum < B) {
                continue;
            }
            else if (sum == B) {
                if (i == nums.size()-1) {
                    break;
                }
                x = nums[i];
                ++i;
                while (i < nums.size()) {
                    num = num * 10 + nums[i];
                    subhand *= 10 ;
                    ++i;
                }
                flag = 2;
                break;
            }
            else {
                while (i < nums.size()) {
                    num = num * 10 + nums[i];
                    subhand *= 10 ;
                    ++i;
                }
                flag = 3;
                break;
            }
        }
        

        if (flag == 3) {
            return (long)(subhand - num);
        }
        else if (flag == 2) {
            if (num == 0) return 0 ;
            num = x * subhand + num ;
            subhand *= 10;
            return (long)(subhand - num) ;
        }
        return 0;
    }


    int addingpar(vector<vector<int>> &dp, int n, int m){
        if(n==0 && m==0) {
            return 1;
        }

        if (dp[n][m] != -1) return dp[n][m];

        int close = 0, open = 0;
        if(m > 0){ close = addingpar(dp, n, m-1); }
        if(n > 0){ open = addingpar(dp, n-1, m+1); }

        return dp[n][m] = open + close;
    }

    int MXC (int N, int K, vector<int> Arr){
        // Write your code here 
        int prev = 0;
        for (int i = 0; i < N; ++i)
        {
            int pick = Arr[i] ^ prev;
            int noPick = prev;
            prev = max(pick, noPick) ;
        }
        vector<vector<int>> dp(prev+1, vector<int>(prev+1, -1));
        int valid = addingpar(dp, prev, 0);
        return (valid * K)%1000000007;
    }

    

    int MXC1 (int N, int K, vector<int> Arr){
        // Write your code here 
        vector<int> dp(N, -1);
        int validPara = maxXOR(Arr, dp, N-1);
        return (validPara * K);
    }


    int maxXOR(vector<int> &nums, vector<int> &dp, int i) {
        if (i == -1) {
            return 0;
        }

        if (dp[i] != -1) return dp[i];
        // pick 
        int pick = nums[i] ^ maxXOR(nums, dp, i-1);
        // dont pick 
        int noPick = maxXOR(nums, dp, i-1);

        return dp[i] = max(pick, noPick) ;
    }
};

int main () {

    long A = 699988854;
    int B = 49;

    Solution Obj1; 
    cout << Obj1.countMoves(A, B);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}