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
    int ans = INT_MIN;

public:
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        rec(root);
        return ans;
    }

    int rec(TreeNode* root) {
        if (root == nullptr) return 0;

        int left_gain = max(rec(root->left), 0);
        int right_gain = max(rec(root->right), 0);

        ans = max(ans, root->val + left_gain + right_gain);

        return max(root->val + left_gain, root->val + right_gain);
    }
};