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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;

        for (int i = 0; i < n; i++) curr = curr->next;

        ListNode* prevNode = head;
        if (curr == NULL) return head->next;

        while (curr->next != NULL) {
            curr = curr->next;
            prevNode = prevNode->next;
        }

        prevNode->next = prevNode->next->next;
        return head;
    }
};