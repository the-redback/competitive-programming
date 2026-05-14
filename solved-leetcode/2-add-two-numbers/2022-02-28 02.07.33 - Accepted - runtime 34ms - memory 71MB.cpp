using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode();
        int onhand = 0;
        ListNode* curr = root;
        while (l1 && l2) {
            work(curr, l1, l2, onhand);
            l1 = l1->next;
            l2 = l2->next;
            curr = curr->next;
        }

        while (l1) {
            work(curr, l1, nullptr, onhand);
            l1 = l1->next;
            curr = curr->next;
            if (onhand == 0) break;
        }

        while (l2) {
            work(curr, l2, nullptr, onhand);
            l2 = l2->next;
            curr = curr->next;
            if (onhand == 0) break;
        }

        if (onhand) {
            curr->next = new ListNode(onhand);
        }
        return root->next;
    }

    void work(ListNode* curr, ListNode* v, ListNode* w, int& onhand) {
        v->val = v->val + onhand;
        if (w) v->val += w->val;
        onhand = v->val / 10;
        v->val = v->val % 10;
        curr->next = v;

        return;
    }
};