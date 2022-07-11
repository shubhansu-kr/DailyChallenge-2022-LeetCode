// https://leetcode.com/problems/binary-tree-right-side-view/

// Given the root of a binary tree, imagine yourself standing on the
// right side of it, return the values of the nodes you can see ordered
// from top to bottom.

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

class Solution1
{
    // Recursion: Space Optmised
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        solve(ans, root);
        return ans;
    }
    void solve(vector<int> &ans, TreeNode *root, int depth = 0)
    {
        if (!root) return;
        if (ans.size() <= depth) ans.push_back(root->val);
        solve(ans, root->right, depth + 1);
        solve(ans, root->left, depth + 1);
    }
};

class Solution
{
    // BruteForce: Recursion
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        unordered_set<int> track;
        solve(ans, track, root);
        return ans;
    }
    void solve(vector<int> &ans, unordered_set<int> &track, TreeNode *root, int depth = 0)
    {
        if (!root) return;
        if (!track.count(depth)){ans.push_back(root->val);track.insert(depth);}

        solve(ans, track, root->right, depth + 1);
        solve(ans, track, root->left, depth + 1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}