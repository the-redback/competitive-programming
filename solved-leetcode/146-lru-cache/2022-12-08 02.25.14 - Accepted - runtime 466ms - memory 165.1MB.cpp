#include <unordered_map>
#include <algorithm>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;

        DLL* node = mp[key];
        remove(node);
        insert(node);
        return node->value;
    }

    void put(int key, int value) {
        if (mp.find(key) == mp.end()) {
            // new key
            DLL* node = new DLL(key, value);
            insert(node);
            mp[key] = node;
        } else {
            // existing key
            DLL* node = mp[key];
            node->value = value;

            remove(node);
            insert(node);
        }

        if (mp.size() > cap) {
            DLL* node = tail->prev;
            remove(node);
            mp.erase(node->key);
            delete node;
        }
    }

private:
    struct DLL {
        int key, value;
        DLL *prev, *next;
        DLL() {
            key = 0, value = 0;
            prev = NULL, next = NULL;
        }

        DLL(int k, int v) {
            key = k, value = v;
            prev = NULL, next = NULL;
        }
    };

    DLL* head = new DLL();
    DLL* tail = new DLL();
    int cap;
    unordered_map<int, DLL*> mp;

    // insert node at the begining of DLL
    void insert(DLL* node) {
        node->prev = head;
        node->next = head->next;

        head->next->prev = node;
        head->next = node;
    }

    // remove node from DLL
    void remove(DLL* node) {
        DLL* prev = node->prev;
        DLL* next = node->next;

        next->prev = prev;
        prev->next = next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */