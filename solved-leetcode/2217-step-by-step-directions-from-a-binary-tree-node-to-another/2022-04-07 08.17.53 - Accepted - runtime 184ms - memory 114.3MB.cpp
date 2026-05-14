#include <string>

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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string l = "", r = "";
        findNode(root, startValue, l);
        findNode(root, destValue, r);

        while (!l.empty() && !r.empty() && l.back() == r.back()) {
            l.pop_back();
            r.pop_back();
        }

        string ans(l.size(), 'U');
        while (!r.empty()) {
            ans += r.back();
            r.pop_back();
        }

        return ans;
    }

    bool findNode(TreeNode* head, int val, string& s) {
        if (!head) return false;
        if (head->val == val) return true;

        bool left = findNode(head->left, val, s);
        bool right = findNode(head->right, val, s);

        if (!left && !right) return false;
        if (left)
            s += 'L';
        else if (right)
            s += 'R';
        return true;
    }
};