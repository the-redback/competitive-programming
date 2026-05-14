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
    ListNode* mergeTwoLists(ListNode* l, ListNode* r) {
        ListNode* keepHead=new ListNode(-1);
        
        ListNode* cur=keepHead;
        
        while(l!=NULL && r!=NULL){
            if(l->val <= r->val){
                cur->next=l;
                l=l->next;
            } else {
                cur->next=r;
                r=r->next;
            }
            cur=cur->next;
        }
        
        if(l==NULL)
            cur->next = r;
        else
            cur->next = l;
        
        return keepHead->next;
    }
};