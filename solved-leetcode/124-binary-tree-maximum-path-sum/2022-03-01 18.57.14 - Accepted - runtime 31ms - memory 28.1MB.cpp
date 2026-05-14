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
    int ans = -100000;

public:
    int maxPathSum(TreeNode* root) {
        ans = -100000;
        maxgain(root);
        return ans;
    }

    int maxgain(TreeNode* root) {
        if (root == nullptr) return -100000;
        int left = maxgain(root->left);
        int right = maxgain(root->right);

        int node = max(root->val, max(left, right) + root->val);
        ans = max(node, ans);
        ans = max(ans, root->val + left + right);
        return node;
    }
};