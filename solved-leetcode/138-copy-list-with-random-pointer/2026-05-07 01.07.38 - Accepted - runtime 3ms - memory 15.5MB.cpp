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
    map<Node*, Node*> mp;

public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        if (mp.find(head) != mp.end()) {
            return mp[head];
        }

        Node* copy = new Node(head->val);
        mp[head] = copy;
        copy->next = copyRandomList(head->next);
        copy->random = copyRandomList(head->random);
        return copy;
    }
};