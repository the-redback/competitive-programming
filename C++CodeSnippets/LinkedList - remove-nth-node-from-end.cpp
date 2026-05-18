
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        ListNode* prev = head;

        for (int i = 0; i < n && curr; i++) {
            curr = curr->next;
        }

        if (curr == nullptr) {
            return head->next;
        }

        while (curr->next != nullptr) {
            curr = curr->next;
            prev = prev->next;
        }

        prev->next = prev->next->next;

        return head;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }

    cout << "\n";
}

int main() {
    // Create: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    printList(head);

    int n = 2;
    Solution sol;
    ListNode* rev = sol.removeNthFromEnd(head, n);
    printList(rev);

    return 0;
}