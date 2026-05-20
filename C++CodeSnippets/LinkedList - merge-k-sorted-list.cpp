
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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

int main() {

    // Create list 1: 1 -> 4 -> 5
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    // Create list 2: 1 -> 3 -> 4
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    // Create list 3: 2 -> 6
    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode*> lists = {l1, l2, l3};
    Solution sol;
    ListNode* result = sol.mergeKLists(lists);

    // Print merged list
    cout << "Merged List: ";
    while (result) {
        cout << result->val;
        if (result->next)
            cout << " -> ";
        result = result->next;
    }
    cout << endl;

    return 0;
}