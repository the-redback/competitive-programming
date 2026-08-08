
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
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
    /*
    # Regular reverse;
     head-> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9
            1 <- 2 <- 3 <- 4 <- 5 <- 6 <- 7 <- 8 <- 9 <- newhead

    K group reverser; k = 3

     head-> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9
            1 <- 2 <- 3    4 <- 5 <- 6    7 <- 8 <- 9
                      ^              ^              ^
                    head            head           head

    Now, connect previous tail to next head.

            1 <- 2 <- 3    4 <- 5 <- 6    7 <- 8 <- 9
            v         ^    v         ^              ^
            |       head   |        head           head
            |         ^    |         ^              ^
            |      newhead |         |              |
            --------->-----|---------               |
                           |                        |
                            ------------------------

    Result:
           3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 9 -> 8 -> 7
    */

    ListNode* reverseK(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (k--) {
            ListNode* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* ktail = nullptr;
        ListNode* newHead = nullptr;

        while (curr) {
            int count = 0;
            while (count < k && curr) {
                curr = curr->next;
                count++;
            }

            if (count != k)
                break;

            ListNode* newRevHead = reverseK(head, k);
            if (newHead == nullptr)
                newHead = newRevHead;

            if (ktail)
                ktail->next = newRevHead;

            ktail = head;
            head = curr;
        }

        if (newHead == nullptr)
            newHead = head;

        if (ktail)
            ktail->next = head;

        return newHead;
    }
};

int main() {
    // Create: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode* rev = sol.reverseKGroup(head, 2);

    // Print reversed list
    while (rev) {
        cout << rev->val;
        if (rev->next) cout << " -> ";
        rev = rev->next;
    }
    cout << "\n";

    return 0;
}