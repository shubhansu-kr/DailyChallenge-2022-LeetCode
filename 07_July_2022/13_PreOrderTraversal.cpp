// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

// Given two integer arrays preorder and inorder where preorder is the preorder 
// traversal of a binary tree and inorder is the inorder traversal of the same tree, 
// construct and return the binary tree.

#include <bits/stdc++.h>
using namespace std ;

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIdx = 0;
        return build(preorder, inorder, rootIdx, 0, inorder.size()-1);
    }
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int& rootIdx, int left, int right) {
        if (left > right) return NULL;
        int pivot = left;  // find the root from inorder
        while(inorder[pivot] != preorder[rootIdx]) pivot++;
        
        rootIdx++;
        TreeNode* newNode = new TreeNode(inorder[pivot]);
        newNode->left = build(preorder, inorder, rootIdx, left, pivot-1);
        newNode->right = build(preorder, inorder, rootIdx, pivot+1, right);
        return newNode;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}