#include <set>
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        set<ListNode*> nodes;

        while (headB) {
            nodes.insert(headB);
            headB = headB->next;
        }

        while (headA) {
            if (nodes.find(headA) != nodes.end()) return headA;
            headA = headA->next;
        }
        return NULL;
    }
};