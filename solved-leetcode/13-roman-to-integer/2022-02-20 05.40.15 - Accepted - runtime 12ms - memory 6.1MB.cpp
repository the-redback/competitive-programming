#include <string>
#include <map>

using namespace std;

map<string, int> mp;

class Solution {
public:
    Solution() {
        static int x = 0;
        if (x == 0) {
            mp["M"] = 1000;
            mp["D"] = 500;
            mp["C"] = 100;
            mp["L"] = 50;
            mp["X"] = 10;
            mp["V"] = 5;
            mp["I"] = 1;
            x = 1;
        }
    }
    int romanToInt(string s) {
        int ans = 0;
        int n = s.size();

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