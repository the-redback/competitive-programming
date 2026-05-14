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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        
        queue<TreeNode*> q;
        vector<vector<int>> result;
        
        int level=0;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> ret(n);
            
            for(int i=0 ;i<n; i++){
                TreeNode* temp = q.front();
                q.pop();
                
                if(level == 0)
                    ret[i]=temp->val;
                else
                    ret[n-i-1] = temp->val;
                
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            
            result.push_back(ret);
            level = !level;
        }
        
        return result;
    }
};