// https://leetcode.com/problems/remove-nth-node-from-end-of-list/

#include <bits/stdc++.h>
using namespace std ;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *prev = nullptr, *q = head;
        while(p) {
            if (n) {
                p = p->next;
                --n;
            }
            else {
                prev = q;
                q = q->next;
                p = p->next;
            }
        }
        if (prev) prev->next = q->next;
        else head = head->next;
        return head;
    }
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = head, *prev = nullptr;
        while(p && n--) {
            p = p->next;
        }
        ListNode *q = head;
        while(p) {
            prev = q;
            q = q->next;
            p = p->next;
        }
        if (prev) {
            prev->next = q->next;
            delete(q);
        }
        else {
            head = head->next;
        }
        return head;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}