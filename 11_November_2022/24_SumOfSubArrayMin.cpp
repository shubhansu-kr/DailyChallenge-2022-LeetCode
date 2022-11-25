// https://leetcode.com/problems/sum-of-subarray-minimums/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n,-1), right(n,n);
        stack<int> st;
        for(int i=0; i<n; i++)
        {
            while(st.size() && arr[i] < arr[st.top()]) st.pop();
            if(st.size()) left[i] = i - st.top();
            else left[i] = i+1;
            st.push(i);
        }
        while(st.size()) st.pop();
        for(int i=n-1; i>=0; i--)
        {
            while(st.size() && arr[i] <= arr[st.top()]) st.pop();
            if(st.size()) right[i] = st.top() - i;
            else right[i] = n - i;
            st.push(i);
        }
        int res = 0;
        for(int i=0; i<n; i++)
        {
            long long prod = (left[i]*right[i])%MOD;
            prod = (prod*arr[i])%MOD;
            res = (res + prod)%MOD;
        } 
        return res%MOD;
    }
};


class Solution
{
    // INT overflow: Runtime err
public:
    int sumSubarrayMins(vector<int> &arr)
    {
        stack<pair<int, int>> in_stk_p, in_stk_n;
        vector<int> left(arr.size()), right(arr.size());

        for (int i = 0; i < arr.size(); i++) left[i] = i + 1;
        for (int i = 0; i < arr.size(); i++) right[i] = arr.size() - i;

        for (int i = 0; i < arr.size(); i++)
        {
            while (!in_stk_p.empty() && in_stk_p.top().first > arr[i]) in_stk_p.pop();
            left[i] = in_stk_p.empty() ? i + 1 : i - in_stk_p.top().second;
            in_stk_p.push({arr[i], i});

            while (!in_stk_n.empty() && in_stk_n.top().first > arr[i])
            {
                auto x = in_stk_n.top();
                in_stk_n.pop();
                right[x.second] = i - x.second;
            }
            in_stk_n.push({arr[i], i});
        }

        int ans = 0, mod = 1e9 + 7;
        for (int i = 0; i < arr.size(); i++)
        {
            ans = (ans + arr[i] * left[i] * right[i]) % mod;
        }
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}