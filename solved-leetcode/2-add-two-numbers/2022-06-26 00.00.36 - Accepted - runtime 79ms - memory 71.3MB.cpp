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
        ListNode* root=new ListNode();
        int carry=0;
        ListNode* curr=root;
        while(l1 || l2){
            int n=0, m=0;
            if(l1){
                n = l1->val;
                l1 = l1->next;
            }
            if(l2) {
                m = l2->val;
                l2 = l2->next;
            }
            
            int sum=n+m+carry;
            carry = sum/10;
            sum = sum%10;
            
            curr->next = new ListNode(sum);
            curr = curr->next;
        }
        
        if(carry){
            curr->next=new ListNode(carry);
        }
        
        return root->next;
    }
};