class Trie {
    struct node {
        bool endmark;
        node* next[26];

        node() {
            endmark = false;
            for (int i = 0; i < 26; i++) {
                next[i] = nullptr;
            }
        }
    };

    node* root;

public:
    Trie() { root = new node(); }

    void insert(string word) {
        node* curr = root;
        for (auto ch : word) {
            int id = ch - 'a';

            if (curr->next[id] == nullptr) curr->next[id] = new node();
            curr = curr->next[id];
        }
        curr->endmark = true;
    }

    bool search(string word) {
        node* curr = root;
        for (auto ch : word) {
            int id = ch - 'a';

            if (curr->next[id] == nullptr) return false;
            curr = curr->next[id];
        }
        return curr->endmark;
    }

    bool startsWith(string prefix) {
        node* curr = root;
        for (auto ch : prefix) {
            int id = ch - 'a';

            if (curr->next[id] == nullptr) return false;
            curr = curr->next[id];
        }

        return curr != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */