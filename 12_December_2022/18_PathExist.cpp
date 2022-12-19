// https://leetcode.com/problems/find-if-path-exists-in-graph/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> parent;     
    int findParent(int node) {
        return parent[node] == node ? node : (parent[node] = findParent(parent[node]));
    }    
    void makeSameGroup(int u , int v) {
        int pu = findParent(u) ; 
        int pv = findParent(v);
        parent[pu] = pv; 
    }
    
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        parent.resize(n);
        for(int i=0;i<n;i++)
            parent[i] = i; 
        
        for(auto e : edges) {
            makeSameGroup(e[0] , e[1]); 
        }                         
        return findParent(source) == findParent(destination); 
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> graph; 
        for(auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n,0);        
        stack<int> st;
        st.push(source);
        visited[source] = 1; 
        
        while(!st.empty()){ 
            auto top = st.top();
            if(top == destination)
                return 1;
            st.pop();
            for(auto node : graph[top]){
                if(!visited[node]){
                    visited[node] = 1;
                    st.push(node); 
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> graph; 
        for(auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> visited(n,0);        
        queue<int> q;
        q.push(source);
        visited[source] = 1; 
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            if(curr == destination)
                return 1; 
            for(auto &node : graph[curr]){
                if(!visited[node]){
                    visited[node] = 1; 
                    q.push(node);
                }
            }
        }
        
        return false;
    }
};

int main () {
    
    return 0;
}