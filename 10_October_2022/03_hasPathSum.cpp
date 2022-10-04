// https://leetcode.com/problems/path-sum/

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
    // WA 
public:
    bool hasPathSum(TreeNode* root, int targetSum, int sum = 0) {
        if (!root) return false;
        return solve(root, targetSum);
    }

    // Prototype
    bool solve(TreeNode* root, int targetSum){
        if (!root) return false;
        if (!root->left && !root->right){
            targetSum -= root->val;
            return targetSum == 0;
        }

        bool left = false;
        if (root->left){
            left = solve(root->left, targetSum-root->val);
            if (left) return left;
        }
        bool right = false;
        if (root->right){
            right = solve(root->right, targetSum-root->val);
            if (right) return right;
        }

        return right||left;
    }
};

class Solution {
    // WA 
public:
    bool hasPathSum(TreeNode* root, int targetSum, int sum = 0) {
        if (!root) return false;
        return solve(root, targetSum);
    }

    // Prototype
    bool solve(TreeNode* root, int targetSum, int sum = 0){
        if (!root){
            return sum == targetSum;
        }

        if (solve(root->left, targetSum, sum+root->val)){
            return true;
        }
        else {
            return solve(root->right, targetSum, sum+root->val);
        }
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}