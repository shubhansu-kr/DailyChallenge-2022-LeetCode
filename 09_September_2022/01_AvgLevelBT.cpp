// https://leetcode.com/problems/average-of-levels-in-binary-tree/

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

class Solution1 {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> sum, count;
        fetchAvg(root, sum, count);
        for (int i = 0; i < sum.size(); ++i)
        {
            sum[i] /= count[i];
        }
        return sum;
    }
    void fetchAvg(TreeNode *root, vector<double> &sum, vector<double> &count, int i = 0) {
        if (!root) return;
        if (sum.size() == i) {
            sum.emplace_back(root->val);
            count.emplace_back(1);
        }
        else {
            sum[i] += root->val;
            count[i]++;
        }
        fetchAvg(root->left, sum, count, i+1);
        fetchAvg(root->right, sum, count, i+1);
        return;
    }
};

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        int depth = depthCount(root);
        vector<double> sum(depth, 0), count(depth, 0);
        fetchAvg(root, sum, count);
        for (int i = 0; i < sum.size(); ++i)
        {
            sum[i] /= count[i];
        }
        return sum;
    }
    int depthCount(TreeNode *root, int i = 0) {
        if (!root) return 0;
        int left = 1 + depthCount(root->left, i+1);
        int right = 1 + depthCount(root->right, i+1);
        return max(left, right);
    }
    void fetchAvg(TreeNode *root, vector<double> &sum, vector<double> &count, int i = 0) {
        if (!root) return;
        sum[i] += root->val;
        count[i]++;
        fetchAvg(root->left, sum, count, i+1);
        fetchAvg(root->right, sum, count, i+1);
        return;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}