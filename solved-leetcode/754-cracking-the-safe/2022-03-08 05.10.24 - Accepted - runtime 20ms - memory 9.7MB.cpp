#include <map>
using namespace std;

class Solution {
public:
    string crackSafe(int n, int k) {
        mx = 1;
        string str = "";
        for (int i = 0; i < n; i++) {
            mx *= k;
            str += '0';
        }
        mp.clear();
        mp[str] = 1;
        dfs(str, n, k);
        return ans;
    }

private:
    map<string, bool> mp;
    int mx;
    string ans;

    bool dfs(string& str, int& n, int& k) {
        if (mp.size() == mx) {
            ans = str;
            return true;
        }

        string s = str.substr(str.size() - n + 1);
        for (int i = 0; i < k; i++) {
            s += i + '0';
            if (mp.find(s) != mp.end()) continue;
            mp[s] = 1;
            str += i + '0';
            if (dfs(str, n, k)) return true;
            str.pop_back();
            mp.erase(s);
        }
        return false;
    }
};