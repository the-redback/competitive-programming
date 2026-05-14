#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstdlib>

using namespace std;

class RandomizedSet {
public:
    RandomizedSet() {}

    bool insert(int val) {
        if (mp.find(val) != mp.end()) return false;
        v.push_back(val);
        mp[val] = v.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;
        int lastVal = v.back();
        int pos = mp[val];

        v[pos] = lastVal;
        mp[lastVal] = pos;

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