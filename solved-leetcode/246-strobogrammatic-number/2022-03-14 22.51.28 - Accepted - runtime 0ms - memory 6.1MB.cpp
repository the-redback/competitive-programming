#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool isStrobogrammatic(string num) {
        mp['0'] = '0';
        mp['1'] = '1';
        mp['8'] = '8';
        mp['6'] = '9';
        mp['9'] = '6';

        for (int i = 0, j = num.size() - 1; i <= j; i++, j--) {
            if (num[i] != mp[num[j]] || num[j] != mp[num[i]]) return false;
        }
        return true;
    }

    map<char, char> mp;
};