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
            l1->val = l1->val + l2->val + onhand;
            onhand = l1->val / 10;
            l1->val = l1->val % 10;
            curr->next = l1;
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1) {
            l1->val = l1->val + onhand;
            onhand = l1->val / 10;
            l1->val = l1->val % 10;
            curr->next = l1;
            curr = curr->next;
            if (onhand == 0) break;
            l1 = l1->next;
        }

        while (l2) {
            l2->val = l2->val + onhand;
            onhand = l2->val / 10;
            l2->val = l2->val % 10;
            curr->next = l2;
            curr = curr->next;
            if (onhand == 0) break;
            l2 = l2->next;
        }

        if (onhand) {
            curr->next = new ListNode(onhand);
        }
        return root->next;
    }
};