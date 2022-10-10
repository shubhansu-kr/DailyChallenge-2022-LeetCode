// https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> uniq;
        return solve(root, uniq, k);
    }
    bool solve(TreeNode *root, unordered_set<int> &u, int k) {
        if (!root) return false;

        if (u.count(k - root->val)) return true;
        else u.insert(root->val);

        if (solve(root->left, u, k)) return true;
        return solve(root->right, u, k);
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}