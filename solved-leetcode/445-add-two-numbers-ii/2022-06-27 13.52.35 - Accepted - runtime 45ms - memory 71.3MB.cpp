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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr;
        int n1 = 0, n2 = 0;

        curr = l1;
        while (curr) {
            n1++;
            curr = curr->next;
        }

        curr = l2;
        while (curr) {
            n2++;
            curr = curr->next;
        }
        ListNode* head = NULL;
        while (n1 > 0 || n2 > 0) {
            int val = 0;
            if (n1 == n2) {
                val = l1->val + l2->val;
                l1 = l1->next;
                l2 = l2->next;
                n1--;
                n2--;
            } else if (n1 > n2) {
                val = l1->val;
                l1 = l1->next;
                n1--;
            } else {
                val = l2->val;
                l2 = l2->next;
                n2--;
            }

            ListNode* tmp = new ListNode(val);
            tmp->next = head;
            head = tmp;
        }

        int carry = 0;
        curr = head;
        ListNode* prev = NULL;
        ListNode* next;

        while (curr) {
            curr->val += carry;
            carry = curr->val / 10;
            curr->val = curr->val % 10;

            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
        if (carry) {
            head = new ListNode(carry);
            head->next = prev;
        }
        return head;
    }
};