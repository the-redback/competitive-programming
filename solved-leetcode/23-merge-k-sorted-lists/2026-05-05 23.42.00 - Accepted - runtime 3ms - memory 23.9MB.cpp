#include <vector>
#include <list>

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
    ListNode* mergeKLists(vector<ListNode*>& lists) { return merge(lists, 0, lists.size() - 1); }

    ListNode* merge(vector<ListNode*>& lists, int left, int right) {
        if (left > right) return nullptr;
        if (left == right) return lists[left];
        int mid = (left + right) / 2;

        ListNode* lnode = merge(lists, left, mid);
        ListNode* rnode = merge(lists, mid + 1, right);
        return merge2pair(lnode, rnode);
    }

    ListNode* merge2pair(ListNode* l, ListNode* r) {
        ListNode* head = new ListNode();
        ListNode* curr = head;

        while (l && r) {
            if (l->val < r->val) {
                curr->next = l;
                l = l->next;
            } else {
                curr->next = r;
                r = r->next;
            }
            curr = curr->next;
        }

        if (l) curr->next = l;
        if (r) curr->next = r;

        return head->next;
    }
};