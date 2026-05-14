class AutocompleteSystem {
public:
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        root=new node();
        for(int i=0; i<sentences.size(); i++){
            insert(sentences[i], times[i]);
        }
    }
    
    vector<string> input(char c) {
        if(c == '#'){
            insert(in, 1);
            in="";
            return {};
        }
        
        in += c;
        node* head = search(in);
        if(head==nullptr)
            return {};
        
        auto comp = [](auto &a, auto &b){
            if(a.first == b.first)
                return a.second < b.second;
            return a.first > b.first;
        };
        
        priority_queue<pair<int, string >, vector<pair<int, string >>, decltype(comp) > minheap(comp);
        
        for(auto p : head->vs){
            minheap.push({p.second, p.first});
            if(minheap.size()>3)
            {
                minheap.pop();
            }
        }
        
        vector<string>ans;
        while(!minheap.empty()){
            ans.push_back(minheap.top().second);
            minheap.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
    struct node{
        bool endmark;
        node* next[26 + 1];
        map<string, int>vs;
        node() {
            endmark=false;
            for(int i=0; i<27; i++){
                next[i] = NULL;
            }
        }
    };
    
    node* root;
    string in="";
    
    void insert(string &s, int f){
        node* curr=root;
        for(auto ch : s){
            int in = ch - 'a';
            if(ch == ' ')
                in=26;
            if(curr->next[in] == NULL){
                curr->next[in] = new node();
            }
            curr = curr->next[in];
            curr->vs[s] += f;
        }
        curr->endmark = true;
    }
    
    node* search(string &s){
        node* curr=root;
        for(auto ch : s){
            int in= ch - 'a';
            if(ch == ' ')
                in=26;
            if(curr->next[in]==nullptr){
                return NULL;
            }
            curr = curr->next[in];
        }
        return curr;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */