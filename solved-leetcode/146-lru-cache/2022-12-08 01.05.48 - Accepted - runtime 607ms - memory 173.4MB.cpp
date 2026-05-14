#include <iostream>
#include <list>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <tuple>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) { cap = capacity; }

    int get(int key) {
        if (keymap.find(key) == keymap.end()) return -1;

        moveToFirst(key);
        return keymap[key].second;
    }

    void put(int key, int value) {
        if (keymap.find(key) == keymap.end()) {
            q.push_front(key);
            cap--;
        } else {
            moveToFirst(key);
        }
        keymap[key] = {q.begin(), value};

        if (cap < 0) {
            keymap.erase(q.back());
            q.pop_back();
            cap++;
        }
    }

private:
    list<int> q;
    unordered_map<int, pair<list<int>::iterator, int> > keymap;
    int cap;

    void moveToFirst(int key) {
        q.erase(keymap[key].first);
        q.push_front(key);
        keymap[key].first = q.begin();
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