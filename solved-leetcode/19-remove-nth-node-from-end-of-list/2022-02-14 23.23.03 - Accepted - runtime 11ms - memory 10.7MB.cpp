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
        int length = 0;
        ListNode* currentNode = head;

        while (currentNode != NULL) {
            currentNode = currentNode->next;
            length++;
        }

        if (length == n) {
            return head->next;
        }

        int nodeBeforeRemovedIndex = length - n - 1;
        currentNode = head;

        for (int i = 0; i < nodeBeforeRemovedIndex; i++) {
            currentNode = currentNode->next;
        }
        currentNode->next = currentNode->next->next;
        return head;
    }
};