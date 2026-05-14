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
    bool isSymmetric(TreeNode* root) {
        stack<pair<TreeNode*,TreeNode*>>s;
        s.push({root,root});
        
        while(!s.empty()){
            pair<TreeNode*,TreeNode*>p = s.top();
            s.pop();
            
            if(p.first == NULL && p.second==NULL) 
                continue;
            if(p.first == NULL || p.second==NULL) 
                return false;
            if(p.first->val != p.second->val)
                return false;
            s.push({p.first->left,p.second->right});
            s.push({p.first->right,p.second->left});
        }
        return true;
    }
};

//iterative




