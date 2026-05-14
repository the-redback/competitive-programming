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
        for(int i=0; i<inorder.size(); i++){
            in[inorder[i]] = i;
        }
        return arrayToTree(preorder, 0, inorder.size()-1 );
    }
    
    unordered_map<int, int> in;
    int index;
    
    TreeNode* arrayToTree(vector<int>& preorder, int left, int right){
        if(left > right)
            return NULL;
        
        int rootval = preorder[index++];
        TreeNode* root=new TreeNode(rootval);
        
        root->left = arrayToTree(preorder, left , in[rootval]  - 1);
        root->right = arrayToTree(preorder, in[rootval] +1, right);
        return root;
    }
};