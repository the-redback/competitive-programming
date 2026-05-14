#include <vector>
#include <list>
#include <queue>

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
// Space: O(k) for priority_queue

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> q;
        for (auto l : lists) {
            if (l) {
                q.push(l);
            }
        }

        ListNode* pre = new ListNode(0);
        ListNode* it = pre;
        while (q.size()) {
            ListNode* top = q.top();
            q.pop();

            it->next = top;
            it = it->next;

            if (top->next) {
                q.push(top->next);
            }
        }
        return pre->next;
    }

    struct compare {
        bool operator()(const ListNode* l1, const ListNode* l2) { return l1->val > l2->val; }
    };
};