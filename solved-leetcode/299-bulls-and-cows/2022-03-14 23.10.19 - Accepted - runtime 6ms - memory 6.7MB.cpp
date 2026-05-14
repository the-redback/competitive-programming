#include <iostream>
#include <string>
#include <map>
#include <tuple>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int bull = 0, cow = 0;

        for (int i = 0; i < secret.size(); i++) {
            if (i < guess.size() && guess[i] == secret[i]) {
                bull++;
            } else {
                if (mp[secret[i]] < 0) cow++;
                if (mp[guess[i]] > 0) cow++;

                mp[secret[i]]++;
                mp[guess[i]]--;
            }
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }

    map<char, int> mp;
};

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);