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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) { return merge(lists, 0, lists.size() - 1); }

    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if (l > r) return nullptr;
        if (l == r) return lists[l];
        int mid = (l + r) / 2;
        ListNode* left = merge(lists, l, mid);
        ListNode* right = merge(lists, mid + 1, r);
        return merge2pair(left, right);
    }

    ListNode* merge2pair(ListNode* left, ListNode* right) {
        ListNode* head = new ListNode();
        ListNode* curr = head;
        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                curr->next = left;
                left = left->next;
            } else {
                curr->next = right;
                right = right->next;
            }
            curr = curr->next;
        }
        if (left != nullptr) curr->next = left;
        if (right != nullptr) curr->next = right;
        return head->next;
    }
};

// divide and concur by recursion