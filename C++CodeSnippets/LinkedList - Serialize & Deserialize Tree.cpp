struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
private:
    void dfs(TreeNode* root, string& s) {
        if (!root) {
            s += "null ";
            return;
        }
        s += to_string(root->val) + " ";
        dfs(root->left, s);
        dfs(root->right, s);
    }

    TreeNode* buildTree(istringstream& ss) {
        string s;
        ss >> s;
        if (s == "null") return nullptr;
        TreeNode* node = new TreeNode(stoi(s));
        node->left = buildTree(ss);
        node->right = buildTree(ss);
        return node;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        dfs(root, s);
        if (s.back() == ' ') s.pop_back();
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        cout << data;
        istringstream ss(data);
        return buildTree(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));