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
    vector<vector<int>> level;

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        helper(root, 0);
        return level;
    }

    void helper(TreeNode* node, int d) {
        if (node == NULL) return;
        if (level.size() == d) level.push_back(vector<int>());
        level[d].push_back(node->val);
        helper(node->left, d + 1);
        helper(node->right, d + 1);
        return;
    }
};