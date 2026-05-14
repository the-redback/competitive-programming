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
    bool hasCycle(ListNode* head) {
        map<ListNode*, bool> mp;
        while (head != NULL) {
            if (mp.find(head) != mp.end()) return true;
            mp[head] = 1;
            head = head->next;
        }
        return false;
    }
};