class Trie {
private:
    struct node{
        bool endmark=false;
        node* next[26];
        node(){
            for(int i=0;i<26; i++)
                next[i]=NULL;            
        }
    }* root;

public:
    Trie() {
        root = new node();
    }
    
    void insert(string word) {
        node* curr=root;
        for(auto s: word){
            int id=s-'a';
            if(curr->next[id] == NULL)
                curr->next[id] = new node();
            curr = curr->next[id];
        }
        curr->endmark=true;
    }
    
    bool search(string word) {
        node* curr=starts(word);
        if(curr == NULL)
            return false;
        return curr->endmark == true;  
    }
    
    bool startsWith(string prefix) {
        node* curr=starts(prefix);
        return curr != NULL;
    }
    
    node* starts(string prefix) {
        node* curr=root;
        for(auto s: prefix){
            int id=s-'a';
            if(curr->next[id] == NULL)
                return NULL;
            curr = curr->next[id];
        }
        return curr;           
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */