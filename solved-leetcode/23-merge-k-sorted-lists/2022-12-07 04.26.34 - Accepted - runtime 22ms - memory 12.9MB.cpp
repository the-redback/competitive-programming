#include <vector>
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

// Time: O(N logk)
// Space: O(1)

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return NULL;

        int interval = 1;
        while (interval < lists.size()) {
            for (int i = 0; i + interval < lists.size(); i += 2 * interval) {
                lists[i] = merge2pair(lists[i], lists[i + interval]);
            }
            interval *= 2;
        }
        return lists[0];
    }

    ListNode* merge2pair(ListNode* l, ListNode* r) {
        // ListNode* head = new ListNode();
        ListNode* head;
        if (l && r) {
            if (l->val < r->val) {
                head = l;
                l = l->next;
            } else {
                head = r;
                r = r->next;
            }
        } else if (l) {
            head = l;
            l = l->next;
        } else if (r) {
            head = r;
            r = r->next;
        }

        ListNode* it = head;

        while (l && r) {
            if (l->val < r->val) {
                it->next = l;
                l = l->next;
            } else {
                it->next = r;
                r = r->next;
            }
            it = it->next;
        }

        if (l) it->next = l;
        if (r) it->next = r;
        return head;
    }
};