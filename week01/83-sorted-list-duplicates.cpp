// https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    // Intuition: in a sorted linked list, all duplicates are next to each other.

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;

        while (curr && curr->next) {
            if (curr->val == curr->next->val) {
                // delete is not necessary in LeetCode

                // ListNode* temp = curr->next;
                curr->next = curr->next->next;
                // delete temp;
            } else {
                // Put this in else so no duplicates are skipped
                curr = curr->next;
            }
        }

        return head;
    }
};