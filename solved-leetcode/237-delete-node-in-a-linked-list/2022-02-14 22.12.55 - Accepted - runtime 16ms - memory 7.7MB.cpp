/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //        auto next=node->next; //pointer
        node->val = node->next->val;
        node->next = node->next->next;
        //        delete next; // delete former next pointer
    }
};