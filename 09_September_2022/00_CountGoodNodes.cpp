// https://leetcode.com/problems/count-good-nodes-in-binary-tree/

// Given a binary tree root, a node X in the tree is named 
// good if in the path from root to X there are no nodes with a value 
// greater than X.
// Return the number of good nodes in the binary tree.

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
    // Using vector
public:
    int goodNodes(TreeNode* root) {
        vector<int> s;
        int count = 0;
        solve(root, count, s);
        return count;
    }

    void insert(vector<int> &s, int val) {
        if (s.size()) {
            for (int i = 0; i < s.size(); ++i)
            {
                if (s[i] > val) {
                    s.insert(s.begin()+i, val);
                    return;
                }
            }
        }
        s.emplace_back(val) ;
    }

    void del(vector<int> &s, int val) {
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == val) {
                s.erase(s.begin()+i);
                return;
            }
        }
    }

    void solve (TreeNode * root, int &count, vector<int> &s) {
        if (!root) return;
        if (s.empty()) ++count;
        else {if (*(s.rbegin()) > root->val){}else ++count;}

        insert(s, root->val);
        solve(root->left, count, s);
        solve(root->right, count, s);
        del(s, root->val);
    }
};

class Solution {
    // Priority Queue wont work either;
public:
    int goodNodes(TreeNode* root) {
        priority_queue<int> s;
        int count = 0;
        solve(root, count, s);
        return count;
    }

    void solve (TreeNode * root, int &count, priority_queue<int> &s) {
        if (!root) return;
        if (s.empty()) ++count;
        else {if (s.top() > root->val){}else ++count;}

        s.push(root->val);
        solve(root->left, count, s);
        solve(root->right, count, s);
        if(root->val = s.top()) s.pop(); 
    }
};

class Solution {
    // WA: Since we are using priority_queue, we are deleting all the instances of an element, 
    // which on repetiion should not have happened;
public:
    int goodNodes(TreeNode* root) {
        set<int> s;
        int count = 0;
        solve(root, count, s);
        return count;
    }

    void solve (TreeNode * root, int &count, set<int> &s) {
        if (!root) return;
        if (s.empty()) ++count;
        else {if (*(s.rbegin()) > root->val){}else ++count;}

        s.insert(root->val);
        solve(root->left, count, s);
        solve(root->right, count, s);
        s.erase(root->val);
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}