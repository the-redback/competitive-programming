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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return nullptr;
        
        int interval=1;
        while(interval<lists.size()){
            for(int i=0;i+interval<lists.size();i+=2*interval){
                lists[i]=merge2pair(lists[i],lists[i+interval]);
            }
            interval*=2;
        }
        return lists[0];
    }
    
    
    ListNode* merge2pair(ListNode* left, ListNode* right){
        ListNode* head=new ListNode();
        ListNode* curr=head;
        while(left!=nullptr && right!=nullptr){
            if(left->val < right->val){
                curr->next=left;
                left = left->next;
            } else {
                curr->next=right;
                right = right->next;
            }
            curr=curr->next;
        }
        if(left!=nullptr)
            curr->next=left;
        if(right!=nullptr)
            curr->next=right;
        return head->next;
    }
};

//divide and concur by iteratiion