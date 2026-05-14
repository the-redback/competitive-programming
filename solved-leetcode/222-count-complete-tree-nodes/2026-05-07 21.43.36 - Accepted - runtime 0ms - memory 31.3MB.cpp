/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) {
            return 0;
        }

        TreeNode* node = root;
        int d = 0;
        while (node->left) {  // calculate depth
            d++;
            node = node->left;
        }

        if (d == 0) return 1;

        int low = 1;
        int high = 1 << d;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nodeExists(root, mid, d)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return (1 << d) - 1 + (low - 1);
    }

    bool nodeExists(TreeNode* root, int pivot, int d) {
        int low = 1;
        int high = 1 << d;

        for (int i = 0; i < d; i++) {
            int mid = low + (high - low) / 2;
            if (pivot <= mid) {
                high = mid;
                root = root->left;
            } else {
                low = mid + 1;
                root = root->right;
            }
        }

        return root != nullptr;
    }
};