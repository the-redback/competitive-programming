#include <map>
#include <algorithm>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;
    Node* left;
    Node* right;
    Node* next;
    Node* random;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr), random(nullptr) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr), random(nullptr) {}
    Node(int _val, vector<Node*> _children) : val(_val), children(_children), left(nullptr), right(nullptr), next(nullptr), random(nullptr) {}
};


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
        if (mp.find(head) != mp.end()) return mp[head];

        Node* hc = new Node(head->val);
        mp[head] = hc;
        hc->next = copyRandomList(head->next);
        hc->random = copyRandomList(head->random);
        return hc;
    }
};