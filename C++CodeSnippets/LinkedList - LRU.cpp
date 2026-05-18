class LRUCache {
private:
    struct DLL {
        int key, value;
        DLL* prev;
        DLL* next;
        DLL() {
            key = value = 0;
            prev = next = nullptr;
        }
        DLL(int k, int v) {
            key = k, value = v;
            prev = next = nullptr;
        }
    };

    DLL* head = new DLL();
    DLL* tail = new DLL();
    unordered_map<int, DLL*> mp;
    int capacity;

    void insert(DLL* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    void remove(DLL* node) {
        DLL* Pnode = node->prev;
        DLL* Nnode = node->next;

        Pnode->next = Nnode;
        Nnode->prev = Pnode;
    }

public:
    LRUCache(int cap) {
        capacity = cap;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        DLL* node = mp[key];
        remove(node);
        insert(node);
        return node->value;
    }

    void put(int key, int value) {
        if (mp.find(key) == mp.end()) {
            DLL* node = new DLL(key, value);
            insert(node);
            mp[key] = node;
        } else {
            DLL* node = mp[key];
            node->value = value;

            remove(node);
            insert(node);
        }

        if (mp.size() > capacity) {
            DLL* node = tail->prev;
            remove(node);
            mp.erase(node->key);
            delete node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */