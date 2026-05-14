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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*>nodes;
        
        while(headB){
            nodes.insert(headB);
            headB = headB->next;
        }
        
        while(headA){
            if(nodes.find(headA) != nodes.end())
                return headA;
            headA=headA->next;
        }
        return NULL;
    }
};