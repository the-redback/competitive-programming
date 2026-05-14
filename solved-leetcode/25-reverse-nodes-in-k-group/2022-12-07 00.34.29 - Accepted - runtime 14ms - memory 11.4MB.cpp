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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* ktail = NULL;
        ListNode* newHead = NULL;

        while (curr) {
            int count = 0;
            while (count < k && curr) {
                curr = curr->next;
                count++;
            }

            if (count != k) break;

            ListNode* newRevHead = reverseK(head, k);
            if (newHead == NULL) newHead = newRevHead;

            if (ktail != NULL) ktail->next = newRevHead;

            ktail = head;
            head = curr;
        }

        if (newHead == NULL) newHead = head;

        if (ktail != NULL) ktail->next = head;

        return newHead;
    }

    ListNode* reverseK(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        while (k) {
            ListNode* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
            k--;
        }
        return prev;
    }
};