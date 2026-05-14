/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
    Node* leftmost;
    Node* curr;
    Node* prev;

public:
    Node* connect(Node* root) {
        if (root == NULL) return root;

        leftmost = root;

        while (leftmost) {
            curr = leftmost;
            prev = NULL;

            leftmost = NULL;

            while (curr) {
                processChild(curr->left);
                processChild(curr->right);

                curr = curr->next;
            }
        }

        return root;
    }

    void processChild(Node* child) {
        if (child == NULL) return;

        if (prev != NULL)
            prev->next = child;
        else
            leftmost = child;

        prev = child;
    }
};