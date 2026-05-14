
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) : val(_val), next(nullptr), random(nullptr) {}
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
public:
    Node* copyRandomList(Node* head) {
        Node* it = head;

        // insert new nodes side by side to original ones in "next" pointer.
        while (it) {
            Node* next = it->next;

            Node* copy = new Node(it->val);
            it->next = copy;
            copy->next = next;

            it = next;
        }

        // Assign random pointers. A->A'->B->B'->C->C'
        //                         |  |   |  |   |  |
        //                         C  C'  A  A'  B  B'

        it = head;
        while (it) {
            if (it->random) {
                it->next->random = it->random->next;
            }
            it = it->next->next;
        }

        // Restore original

        it = head;
        Node* root = new Node(0);
        Node* prev = root;

        while (it) {
            Node* next = it->next->next;
            prev->next = it->next;
            prev = prev->next;

            it->next = next;
            it = it->next;
        }

        return root->next;
    }
};