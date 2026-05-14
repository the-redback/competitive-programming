class LRUCache {
public:
    LRUCache(int capacity) { cap = capacity; }

    int get(int key) {
        if (keymap.find(key) == keymap.end()) return -1;
        moveToFirst(key);
        return keymap[key];
    }

    void put(int key, int value) {
        if (keymap.find(key) == keymap.end()) {
            q.push_front(key);
            qmap[key] = q.begin();
            cap--;
        } else {
            moveToFirst(key);
        }
        keymap[key] = value;

        if (cap < 0) {
            keymap.erase(q.back());
            qmap.erase(q.back());
            q.pop_back();
            cap++;
        }
    }

private:
    list<int> q;
    unordered_map<int, list<int>::iterator> qmap;
    unordered_map<int, int> keymap;
    int cap;

    void moveToFirst(int key) {
        q.erase(qmap[key]);
        q.push_front(key);
        qmap[key] = q.begin();
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