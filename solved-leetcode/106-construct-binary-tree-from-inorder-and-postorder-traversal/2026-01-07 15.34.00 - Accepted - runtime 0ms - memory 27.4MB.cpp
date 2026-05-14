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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        index = postorder.size()-1;
        for(int i = 0; i < inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }

        return arrayToTree(postorder, 0, inorder.size() - 1);
    }

    unordered_map<int, int> inorderMap;
    int index;

    TreeNode* arrayToTree(vector<int> & postorder, int i, int j){
        if( i > j )
            return nullptr;
        
        int rootvalue = postorder[index--];
        TreeNode* root = new TreeNode(rootvalue);

        root->right = arrayToTree(postorder, inorderMap[rootvalue] + 1, j);
        root->left = arrayToTree(postorder, i, inorderMap[rootvalue] - 1);

        return root;
    }
};