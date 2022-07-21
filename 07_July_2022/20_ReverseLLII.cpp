// https://leetcode.com/problems/reverse-linked-list-ii/

// Given the head of a singly linked list and two integers left and
// right where left <= right, reverse the nodes of the list from position
// left to position right, and return the reversed list.

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    ListNode *next;
    int val;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(0), *pre = dummy, *cur;
        dummy->next = head;
        for (int i = 0; i < left - 1; i++){pre = pre->next;}
        cur = pre->next;
        for (int i = 0; i < right - left; i++)
        {
            ListNode *temp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = temp;
        }
        return dummy->next;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}