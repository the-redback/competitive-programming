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

// Time: O(N logk)
// Space: O(1)

struct Compare {
    bool operator()(ListNode* l, ListNode* r){
        return l->val > r->val;
    }
};

class Solution {
    public: ListNode * mergeKLists(vector < ListNode * > & lists) {
       priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        for(auto l : lists ){
            if(l) pq.push(l);
        }

        ListNode* head = new ListNode();
        ListNode* curr = head;

        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();

            curr->next = new ListNode(node->val);
            if(node->next)
                pq.push(node->next);

            curr = curr->next;
        }

        return head->next;
    }
};