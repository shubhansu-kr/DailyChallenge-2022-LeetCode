// https://leetcode.com/problems/path-sum-ii/

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
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> ans;
        vector<int> sub;
        solve(root, targetSum, 0, ans, sub);
        return ans;
    }

    void solve(TreeNode *root, int targetSum, int sum, vector<vector<int>> &ans, vector<int> &sub)
    {
        if (!root) return;
        sub.emplace_back(root->val);
        sum += root->val;
        if (!root->left && !root->right) {
            if (sum == targetSum) ans.emplace_back(sub);
            sum -= root->val;
            sub.pop_back();
            return;
        }
        if (root->left){solve(root->left, targetSum, sum, ans, sub);}
        if (root->right){solve(root->right, targetSum, sum, ans, sub);}
        sum -= root->val;
        sub.pop_back();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}