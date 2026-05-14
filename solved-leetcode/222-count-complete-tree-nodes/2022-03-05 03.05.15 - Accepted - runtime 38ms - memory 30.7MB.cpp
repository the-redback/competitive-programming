/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        TreeNode* head = root;
        if (root == nullptr) return 0;

        int d = 0;
        while (head->left != nullptr) {
            d++;
            head = head->left;
        }
        if (d == 0) return 1;

        head = root;
        int low = 1, high = 1 << d;
        while (low <= high) {
            int pivot = low + (high - low) / 2;
            if (nodeExists(head, pivot, d))
                low = pivot + 1;
            else
                high = pivot - 1;
        }
        // low is the first node number that doesn't exist
        return (1 << d) - 1 + low - 1;
    }

private:
    bool nodeExists(TreeNode* head, int idx, int d) {
        int low = 1, high = 1 << d;
        for (int i = 0; i < d; i++) {
            int mid = low + (high - low) / 2;
            if (idx <= mid) {
                high = mid;
                head = head->left;
            } else {
                low = mid + 1;
                head = head->right;
            }
        }
        return head != nullptr;
    }
};

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
