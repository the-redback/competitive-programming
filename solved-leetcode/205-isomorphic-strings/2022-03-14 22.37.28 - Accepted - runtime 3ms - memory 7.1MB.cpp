#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <tuple>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        for (int i = 0; i < s.size(); i++) {
            if (mp.find(s[i]) == mp.end() && rev.find(t[i]) == rev.end()) {
                mp[s[i]] = t[i];
                rev[t[i]] = s[i];
            } else if (mp[s[i]] != t[i] || rev[t[i]] != s[i])
                return false;
        }

        return true;
    }

private:
    map<char, char> mp;
    map<char, char> rev;
};

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);