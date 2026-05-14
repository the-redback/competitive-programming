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
        ListNode* ktail = NULL;
        ListNode* new_head = NULL;
        ListNode* prev = NULL;

        while (curr) {
            int count = 0;
            while (count < k && curr) {
                curr = curr->next;
                count++;
            }

            if (count == k) {
                ListNode* revHead = reverseLinkedList(head, k);

                if (new_head == NULL) new_head = revHead;

                if (ktail != NULL) ktail->next = revHead;

                ktail = head;
                head = curr;
            }
        }

        if (ktail != NULL) ktail->next = head;

        if (new_head == NULL) new_head = head;

        return new_head;
    }

    ListNode* reverseLinkedList(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (k > 0) {
            ListNode* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
            k--;
        }

        return prev;
    }
};