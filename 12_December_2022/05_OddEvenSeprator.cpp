// https://leetcode.com/problems/odd-even-linked-list/

#include <bits/stdc++.h>
using namespace std;

//  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }

        ListNode *oddTail = head;
        ListNode *evenHead = head->next;

        ListNode *ptr = evenHead;
        while (ptr != NULL && ptr->next != NULL)
        {
            oddTail->next = ptr->next;
            ptr->next = ptr->next->next;
            oddTail = oddTail->next;
            ptr = ptr->next;
        }
        oddTail->next = evenHead;
        return head;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}