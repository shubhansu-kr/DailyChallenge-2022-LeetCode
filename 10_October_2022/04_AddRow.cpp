// https://leetcode.com/problems/add-one-row-to-tree/

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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1){
            TreeNode *p = new TreeNode(val, root, nullptr);
            return p;
        }
        solve(root, val, depth);
        return root;
    }

    void solve(TreeNode *root, int val, int depth, int i = 1){
        if (!root) return;
        if (i == depth-1){
            TreeNode*p = new TreeNode(val, root->left, nullptr);
            TreeNode*q = new TreeNode(val, nullptr, root->right);

            root->left = p, root->right = q;
            return;
        }

        solve(root->left, val, depth, i+1);
        solve(root->right, val, depth, i+1);
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}