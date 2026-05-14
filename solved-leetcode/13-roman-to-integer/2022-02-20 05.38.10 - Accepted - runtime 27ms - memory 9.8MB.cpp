#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int n = s.size();
        map<string, int> mp;
        mp["M"] = 1000;
        mp["D"] = 500;
        mp["C"] = 100;
        mp["L"] = 50;
        mp["X"] = 10;
        mp["V"] = 5;
        mp["I"] = 1;

        for (int i = 0; i < n; i++) {
            string str = "";
            str += s[i];
            int curr = mp[str];
            if (i + 1 < n) {
                string nextstr = "";
                nextstr += s[i + 1];
                if (curr < mp[nextstr]) {
                    curr = mp[nextstr] - curr;
                    i++;
                }
            }
            ans += curr;
        }

        return ans;
    }
};