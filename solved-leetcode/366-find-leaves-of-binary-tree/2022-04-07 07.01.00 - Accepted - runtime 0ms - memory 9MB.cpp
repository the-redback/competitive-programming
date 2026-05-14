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
    vector<vector<int>> findLeaves(TreeNode* root) {
        ans.clear();
        getHeight(root);
        return ans;
    }
    
    vector<vector<int>>ans;
    
    int getHeight(TreeNode *root){
        if(root == nullptr)
            return -1;
        
        int left=getHeight(root->left);
        int right=getHeight(root->right);
        int height=max(left, right)+1;
        
        if(ans.size()==height) 
            ans.push_back({});
        ans[height].push_back(root->val);
        
        return height;
    }
};