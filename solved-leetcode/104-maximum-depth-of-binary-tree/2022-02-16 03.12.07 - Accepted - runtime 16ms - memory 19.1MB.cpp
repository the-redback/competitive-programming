#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        queue<pair<TreeNode*, int>> q;
        int max_depth = 0;

        q.push({root, 1});
        while (!q.empty()) {
            pair<TreeNode*, int> pr = q.front();
            max_depth = max(pr.second, max_depth);

            q.pop();

            if (pr.first->left != NULL) {
                q.push({pr.first->left, pr.second + 1});
            }
            if (pr.first->right != NULL) {
                q.push({pr.first->right, pr.second + 1});
            }
        }
        return max_depth;
    }
};