/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    map<Node*,Node*>mp;
    private: Node* getDeepCopy(Node* head){
        if(head==nullptr)
            return head;
        if(mp.find(head)!=mp.end())
            return mp[head];
        
        Node* hc=new Node(head->val);
        mp[head]=hc;
        
        return hc;
    }
public:
    Node* copyRandomList(Node* head) {
        if(head==nullptr)
            return head;
        
        Node* hc=getDeepCopy(head);
        Node* curr=hc;
        while(head){
            curr->next=getDeepCopy(head->next);
            curr->random=getDeepCopy(head->random);
            
            curr=curr->next;
            head=head->next;
        }
        return hc;
    }
};