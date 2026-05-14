
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <cstddef>
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL) return root;

        // find the key first
        if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } else if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            if (root->left == NULL && root->right == NULL)
                root = NULL;
            else if (root->right) {
                int tmp = successor(root);
                root->val = tmp;
                root->right = deleteNode(root->right, tmp);
            } else {
                int tmp = predecessor(root);
                root->val = tmp;
                root->left = deleteNode(root->left, tmp);
            }
        }
        return root;
    }

    int successor(TreeNode* root) {
        root = root->right;
        while (root->left) root = root->left;
        return root->val;
    }

    int predecessor(TreeNode* root) {
        root = root->left;
        while (root->right) root = root->right;
        return root->val;
    }
};