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
        ListNode* currentNode = head;
        
        for(int i=0;i<n;i++)
            currentNode=currentNode->next;
        
        if(currentNode == NULL)
            return head->next;
        
        ListNode* nodeBeforeRemoved = head;
        
        while(currentNode->next != NULL){
            currentNode = currentNode->next;
            nodeBeforeRemoved = nodeBeforeRemoved->next;      
        }
        
        nodeBeforeRemoved->next = nodeBeforeRemoved->next->next;
        return head;
    }
};