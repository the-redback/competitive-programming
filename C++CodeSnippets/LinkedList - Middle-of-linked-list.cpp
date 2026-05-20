
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
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main() {

    // Create: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Print original list
    ListNode* temp = head;

    while (temp) {
        cout << temp->val;

        if (temp->next)
            cout << " -> ";

        temp = temp->next;
    }

    cout << "\n";

    Solution sol;

    ListNode* mid = sol.middleNode(head);

    // Print middle node onward
    while (mid) {
        cout << mid->val;

        if (mid->next)
            cout << " -> ";

        mid = mid->next;
    }

    cout << "\n";

    return 0;
}