// https://leetcode.com/problems/range-sum-of-bst/

#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int H) {
        if(!root) return 0;
        return  (root -> val >= L && root -> val <= H ? root -> val : 0) +  // add root's value if it lies within [L, H]
                rangeSumBST(root -> left, L, H) +   // recurse left
                rangeSumBST(root -> right, L, H);   // recurse right
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}