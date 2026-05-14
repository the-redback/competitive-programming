class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end() )
            return -1;
        node* currnode = mp[key];
        remove(currnode);
        insert(currnode);
        return currnode->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end() ){
            node* temp = mp[key];
            remove(mp[key]);
            temp->value = value;
            insert(temp);
        } else {
            insert(new node(key, value));
        }

        if(mp.size() > cap){
            remove(tail->prev);
        }
    }

private:
    struct node{
        int key,value;
        node *prev, *next;
        
        node(int k, int v){
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };
    
    int cap;
    node* head = new node(0,0);
    node* tail = new node(0,0);
    unordered_map<int, node*> mp;
    
    void insert(node* currnode){
        currnode->next = head->next;
        currnode->prev = head;
        
        head->next->prev = currnode;
        head->next = currnode;
        
        mp[currnode->key] = currnode;
    }
    
    void remove(node* currnode){
        mp.erase(currnode->key);
        
        currnode->next->prev = currnode->prev;
        currnode->prev->next = currnode->next;
    }
    
};


static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */