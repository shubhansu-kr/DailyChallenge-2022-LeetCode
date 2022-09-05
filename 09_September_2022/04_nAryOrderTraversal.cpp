// https://leetcode.com/problems/n-ary-tree-level-order-traversal/

#include <bits/stdc++.h>
using namespace std ;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        traverse(root, ans) ;
        return ans; 
    }
    void traverse(Node *root, vector<vector<int>> &ans, int i = 0) {
        if (!root) return;
        if (ans.size() == i) ans.push_back({root->val});
        else ans[i].emplace_back(root->val);
        for (int j = 0; j < root->children.size(); ++j)
        {
            traverse(root->children[j], ans, i+1);
        }
        return;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}