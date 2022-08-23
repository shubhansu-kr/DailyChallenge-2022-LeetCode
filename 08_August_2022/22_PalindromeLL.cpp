// https://leetcode.com/problems/palindrome-linked-list/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution2
{
    // Reverse half the linked list and check palindrome
    // TC: O(n)
    // SC: O(n)
public:
    bool isPalindrome(ListNode *head)
    {
        if (head->next == nullptr) return true;
        ListNode *back = head, *forward = head;
        while(forward && forward->next) {
            back = back->next;
            forward = forward->next->next;
        }
        ListNode* mid = new ListNode(back->val, back->next);
        back->next = nullptr;

        ListNode *headReverse = reverseLL(mid);
        while(headReverse && head){
            if (head->val != headReverse->val) return false;
            head=head->next;
            headReverse = headReverse->next;
        }
        return true;
    }
    ListNode* reverseLL(ListNode* head) {
        if (!head) return head;
        ListNode* prev = nullptr;
        while(head) {
            ListNode *temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
};

class Solution1
{
    // BruteForce: Reverse the linked list and check palindrome
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *headReverse = reverseLL(head);
        while(head){
            if (head->val != headReverse->val) return false;
            head=head->next;
            headReverse = headReverse->next;
        }
        return true;
    }
    ListNode* reverseLL(ListNode* head) {
        if (!head) return head;
        ListNode* prev = nullptr;
        while(head) {
            ListNode *temp = head->next;
            head->next = prev;
            prev = head;
            head = temp;
        }
        return prev;
    }
};

class Solution
{
    // BruteForce: Reverse the linked list and check palindrome
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *headReverse = reverseLL(head);
        while(head){
            if (head->val != headReverse->val) return false;
            head=head->next;
            headReverse = headReverse->next;
        }
        return true;
    }
    ListNode* reverseLL(ListNode* head) {
        if (!head) return head;
        ListNode* newHead = nullptr;
        while(head) {
            ListNode *temp = new ListNode(head->val, newHead);
            newHead = temp;
            head = head->next;
        }
        return newHead;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}