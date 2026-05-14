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
    unordered_map<Node*, Node*> mp;

private:
    void getDeepCopy(Node* head) {
        while (head) {
            Node* hc = new Node(head->val);
            mp[head] = hc;
            head = head->next;
        }
        return;
    }

public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return head;
        getDeepCopy(head);

        Node* hc = mp[head];
        Node* curr = head;
        while (curr) {
            mp[curr]->next = mp[curr->next];
            mp[curr]->random = mp[curr->random];

            curr = curr->next;
        }
        return hc;
    }
};

// Fast I/O; 4 ms
static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);