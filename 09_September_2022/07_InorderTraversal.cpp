// https://leetcode.com/problems/binary-tree-inorder-traversal/

#include <bits/stdc++.h>
using namespace std ;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }
    void inorder(TreeNode *root, vector<int> &ans) {
        if (!root) return ;
        inorder(root->left, ans);
        ans.emplace_back(root->val);
        inorder(root->right, ans);
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}