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
    ListNode* root;
public:
    bool isPalindrome(ListNode* head) {
        root=head;
        return rec(head);
    }
    
    bool rec(ListNode* curr){
        if(curr == NULL){
            return true;
        }
        if(!rec(curr->next))
            return false;
        if(curr->val != root->val)
            return false;
        root = root->next;
        return true;
    }
};