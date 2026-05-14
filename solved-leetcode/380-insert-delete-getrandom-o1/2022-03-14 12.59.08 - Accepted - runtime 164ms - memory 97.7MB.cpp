#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <tuple>
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
        v.pop_back();

        v[mp[val]] = lastVal;
        mp[lastVal] = mp[val];

        mp.erase(val);
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

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);