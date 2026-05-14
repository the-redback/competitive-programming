#include <iostream>
#include <list>
#include <tuple>

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

// Memory: O(1)
// Time: O(N)

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* it = head;
        Node* next;

        // include new nodes along with olders side by side
        while (it) {
            next = it->next;

            Node* copy = new Node(it->val);

            it->next = copy;
            copy->next = next;

            it = next;
        }

        // Assign random pointers
        it = head;
        while (it) {
            if (it->random) {
                it->next->random = it->random->next;
            }
            it = it->next->next;
        }

        // Restore original list
        it = head;
        Node* copyHead = new Node(-1);
        Node* prevCopy = copyHead;

        while (it) {
            next = it->next->next;

            // handle copy
            Node* copy = it->next;
            prevCopy->next = copy;
            prevCopy = copy;

            // Restore original
            it->next = next;
            it = next;
        }

        return copyHead->next;
    }
};

// Fast I/O; 4 ms
static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);