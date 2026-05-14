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
        if(root==NULL) return 0;
        stack<pair<TreeNode*,int>>st;
        int max_depth=0;
        
        st.push({root,1});
        while(!st.empty()){
            pair<TreeNode*,int> pr = st.top();
            max_depth=max(pr.second,max_depth);
            
            st.pop();
            
            if(pr.first->left != NULL){
                st.push({pr.first->left,pr.second+1});
            }
            if(pr.first->right != NULL){
                st.push({pr.first->right,pr.second+1});
            }
        }
        return max_depth;
    }
};