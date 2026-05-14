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
    void reorderList(ListNode* head) {
        // find middle point
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse second half
        ListNode* curr = slow;
        ListNode* prev = NULL;
        ListNode* tmp;
        while (curr) {
            tmp = curr->next;
            curr->next = prev;

            prev = curr;
            curr = tmp;
        }

        ListNode* first = head;
        ListNode* second = prev;
        while (second->next) {
            tmp = first->next;
            first->next = second;
            first = tmp;

            tmp = second->next;
            second->next = first;
            second = tmp;
        }
    }
};