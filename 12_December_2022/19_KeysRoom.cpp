// https://leetcode.com/problems/keys-and-rooms/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int> visited(n, 0);
        unordered_set<int> keys;
        queue<int> que;
        for(auto &it: rooms[0]) {
            que.push(it);
        }
        visited[0] = 1;
        keys.insert(0);
        while(que.size()){
            int ind = que.front();
            if (!visited[ind]) {
                keys.insert(ind);
                for(auto &it: rooms[ind]){
                    que.push(it);
                }
                visited[ind] = 1;
            }
            que.pop();
        }
        return keys.size() == n;
    }
};

int main () {
    
    return 0;
}