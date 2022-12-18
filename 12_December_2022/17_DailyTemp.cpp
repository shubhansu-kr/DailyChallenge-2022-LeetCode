// https://leetcode.com/problems/daily-temperatures/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> mystack;
        vector<int> ret;
        ret.push_back(0);
        mystack.push(temperatures.size()-1);
        for(int i=temperatures.size()-2;i>=0;i--){
            int val = mystack.top();
            if(temperatures[i]<temperatures[val]){
                ret.push_back(val-i);
                mystack.push(i);
            }
            else{
                while(temperatures[i]>=temperatures[val]){
                    mystack.pop();
                    if(mystack.empty()){
                        break;
                    }
                    val = mystack.top();
                }
                if(!mystack.empty()){
                ret.push_back(val-i);}
                else{
                ret.push_back(0);
                }
                mystack.push(i);
            }
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};

int main () {
    
    return 0;
}