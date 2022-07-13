// https://leetcode.com/problems/binary-tree-level-order-traversal/

// Given the root of a binary tree, return the level order traversal
// of its nodes' values. (i.e., from left to right, level by level).

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
    // Using Map 
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        map<int, vector<int>> m;
        solve(m, root);
        for(auto it: m) ans.emplace_back(it.second);
        return ans;
    }

    void solve(map<int, vector<int>> &m, TreeNode *root, int depth = 0) {
        if (!root) return;
        m[depth].emplace_back(root->val);
        solve(m, root->left, depth+1);
        solve(m, root->right, depth+1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}