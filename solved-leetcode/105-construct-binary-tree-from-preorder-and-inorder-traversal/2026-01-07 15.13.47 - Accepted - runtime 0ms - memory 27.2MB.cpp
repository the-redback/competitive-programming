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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        index=0;
        for(int i = 0; i < inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }
        return arrayToTree(preorder, 0, inorder.size() - 1);
    }

    unordered_map<int, int> inorderMap;
    int index;

    TreeNode* arrayToTree(vector<int> & preorder, int i, int j){
        if( i > j )
            return nullptr;
        
        int rootvalue = preorder[index++];
        TreeNode* root = new TreeNode(rootvalue);

        root->left = arrayToTree(preorder, i, inorderMap[rootvalue] - 1);
        root->right = arrayToTree(preorder, inorderMap[rootvalue] + 1, j);

        return root;
    }
};