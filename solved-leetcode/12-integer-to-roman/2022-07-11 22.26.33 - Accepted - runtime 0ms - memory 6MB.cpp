#include <vector>

using namespace std;

vector<string> str = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};

class Solution {
public:
    string intToRoman(int num) {
        string ans = "";
        for (int i = 0; i < str.size(); i++) {
            if (val[i] > num) continue;
            int k = num / val[i];
            num -= k * val[i];
            while (k--) {
                ans += str[i];
            }
        }
        return ans;
    }
};