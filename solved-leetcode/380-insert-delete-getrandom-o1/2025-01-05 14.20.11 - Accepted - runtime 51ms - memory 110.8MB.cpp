#include <iostream>
using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }

    bool insert(int val) {
        if (mp.find(val) != mp.end()) return false;
        v.push_back(val);
        mp[val] = v.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;
        int lastVal = v.back();
        int idx = mp[val];

        v[idx] = lastVal;
        mp[lastVal] = idx;

        mp.erase(val);
        v.pop_back();
        return true;
    }

    int getRandom() {
        int random = rand() % mp.size();
        return v[random];
    }

private:
    unordered_map<int, int> mp;
    vector<int> v;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */