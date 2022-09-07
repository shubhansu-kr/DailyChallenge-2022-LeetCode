// https://leetcode.com/problems/construct-string-from-binary-tree/

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
    string tree2str(TreeNode* root) {
        string ans = to_string(root->val);
		if (root->left) 
			ans += "(" + tree2str(root->left) + ")";
		if (root->right) {
			if (!root->left) ans += "()"; 
			ans += "(" + tree2str(root->right) + ")"; 
		}
		return ans;
    }
    void preOrder(TreeNode *root, string &ans) {
        if (!root) return;

        ans += to_string(root->val);
        ans.append("(");
        preOrder(root->left, ans);
        preOrder(root->right, ans);
        ans.append(")");
        return;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}