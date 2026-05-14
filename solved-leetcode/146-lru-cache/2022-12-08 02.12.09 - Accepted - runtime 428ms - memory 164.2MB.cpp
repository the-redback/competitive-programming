#include <iostream>
using namespace std;

// Time complexity : O(1) for put and get.
// Space complexity : O(capacity) for map and doublelinkedlist

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
        if (mp.find(key) != mp.end()) {
            DLL* node = mp[key];
            node->value = value;

            remove(mp[key]);
            insert(node);
        } else {
            DLL* node = new DLL(key, value);
            insert(node);
            mp[key] = node;
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

        DLL(int k, int v) {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };

    int cap;
    DLL* head = new DLL(0, 0);
    DLL* tail = new DLL(0, 0);
    unordered_map<int, DLL*> mp;

    // insert node at the beginning of DLL
    void insert(DLL* node) {
        node->next = head->next;
        node->prev = head;

        head->next->prev = node;
        head->next = node;
    }

    // remove node from DLL
    void remove(DLL* node) {
        DLL* prev = node->prev;
        DLL* next = node->next;

        prev->next = next;
        next->prev = prev;
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