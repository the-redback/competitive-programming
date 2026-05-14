#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


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

        int length = 0;
        while (curr) {
            length++;
            curr = curr->next;
        }

        if (length == n) return head->next;

        length = length - n;  // node before nth node.

        curr = head;
        while (length > 1) {
            curr = curr->next;
            length--;
        }

        cout << curr->val << " ";

        curr->next = curr->next->next;
        return head;
    }
};