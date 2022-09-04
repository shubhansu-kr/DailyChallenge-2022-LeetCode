// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

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
    struct Node {
        TreeNode* n;
        int x, y;
    };
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        map<int, map<int, vector<int>>> mp;
        queue<Node*> q;
        q.push(new Node{root, 0, 0});
        while(!q.empty()) {
            Node* node = q.front();
            q.pop();
            if(node->n->left) q.push(new Node{node->n->left, node->x - 1, node->y + 1});
            if(node->n->right) q.push(new Node{node->n->right, node->x + 1, node->y + 1});
            mp[node->x][node->y].push_back(node->n->val);
        }
        for(pair<int, map<int, vector<int>>> p1 : mp) {
            ans.push_back({});
            for(pair<int, vector<int>> p2 : p1.second) {
                vector<int> v = p2.second;
                sort(v.begin(), v.end());
                ans.back().insert(ans.back().end(), v.begin(), v.end());
            }
        }
        return ans;
    }
};


// class Solution {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
//         map<int, map<int, set<int>>> nodes;
//         queue<pair<TreeNode*, pair<int, int>>> todo;
//         todo.push({root, {0, 0}});
//         while (!todo.empty()) {
//             auto p = todo.front();
//             todo.pop();
//             TreeNode* node = p.first;
//             int x = p.second.first, y = p.second.second;
//             nodes[x][y].insert(node -> val);
//             if (node -> left) {
//                 todo.push({node -> left, {x - 1, y + 1}});
//             }
//             if (node -> right) {
//                 todo.push({node -> right, {x + 1, y + 1}});
//             }
//         }
//         vector<vector<int>> ans;
//         for (auto p : nodes) {
//             vector<int> col;
//             for (auto q : p.second) {
//                 col.insert(col.end(), q.second.begin(), q.second.end());
//             }
//             ans.push_back(col);
//         }
//         return ans;
//     }
// };

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}