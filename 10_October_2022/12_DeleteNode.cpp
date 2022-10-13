// https://leetcode.com/problems/delete-node-in-a-linked-list/

#include <bits/stdc++.h>
using namespace std ;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}