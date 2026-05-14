#include <string>

using namespace std;

class WordDictionary {
    struct node {
        bool endmark;
        node* next[26];
        node() {
            endmark = false;
            for (int i = 0; i < 26; i++) next[i] = NULL;
        }
    }* root;

    bool searchInTrie(string& s, int i, node* curr) {
        if (i == s.size()) return curr->endmark == true;

        for (; i < s.size(); i++) {
            if (s[i] == '.') {
                for (int j = 0; j < 26; j++) {
                    if (curr->next[j] && searchInTrie(s, i + 1, curr->next[j])) return true;
                }
                return false;
            }
            int id = s[i] - 'a';
            if (curr->next[id] == NULL) return false;
            curr = curr->next[id];
        }
        return curr->endmark == true;
    }

public:
    WordDictionary() { root = new node(); }

    void addWord(string word) {
        node* curr = root;
        for (auto s : word) {
            int id = s - 'a';
            if (curr->next[id] == NULL) curr->next[id] = new node();
            curr = curr->next[id];
        }
        curr->endmark = true;
    }

    bool search(string word) { return searchInTrie(word, 0, root); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */