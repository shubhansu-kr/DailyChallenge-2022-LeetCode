// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

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
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_set<int> freq;
        return solve(root, freq);            
    }
    int solve(TreeNode *root, unordered_set<int> &freq) {
        if (!root) {return freq.size() < 2;}
        if(freq.count(root->val)) freq.erase(root->val);
        else freq.insert(root->val);
        int left = solve(root->left, freq);
        int right = 0; 
        if (root->left || root->right) right = solve(root->right, freq);
        return left + right;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}
