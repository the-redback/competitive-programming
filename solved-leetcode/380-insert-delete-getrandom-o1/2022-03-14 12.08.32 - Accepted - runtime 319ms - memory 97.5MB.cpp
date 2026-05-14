class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.find(val) != mp.end())
            return false;
        mp[val] = true;
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val) == mp.end())
            return false;
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        auto it = mp.begin();
        int random = rand() % mp.size();
        advance(it, random);
        return it->first;
    }
private:
    unordered_map<int, bool> mp;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);