// https://leetcode.com/problems/reverse-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // Intuition: visit the nodes in the list and reverse the links.

    // Recursive solution
    ListNode* reverseList(ListNode* head) {
        // Reverse of empty list is empty
        if (!head)
            return nullptr;

        // Reverse of a single node is itself
        if (!head->next)
            return head;

        // Recursive call: reverse the rest of the list
        ListNode* newHead = reverseList(head->next);

        // Reverse this link
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }

    // Iterative solution
    ListNode* reverseListIterative(ListNode* head) {
        ListNode* curr = head;
        // Keep track of previous to reverse links
        // prev starts as nullptr so head->next = nullptr (original head is end
        // of new list)
        ListNode* prev = nullptr;

        while (curr) {
            ListNode* temp = curr->next;

            // Reverse link
            curr->next = prev;

            prev = curr;
            curr = temp;
        }

        return prev;
    }
};
