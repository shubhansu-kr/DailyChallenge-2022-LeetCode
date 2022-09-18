// https://leetcode.com/problems/trapping-rain-water/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), left=0, right=n-1, res=0, maxleft=0, maxright=0;
        while(left<=right){
            if(height[left]<=height[right]){
                if(height[left]>=maxleft) maxleft=height[left];
                else res+=maxleft-height[left];
                left++;
            }
            else{
                if(height[right]>=maxright) maxright= height[right];
                else res+=maxright-height[right];
                right--;
            }
        }
        return res;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}