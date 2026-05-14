#include <string>
#include <vector>

using namespace std;

class Solution {
    vector<int> value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> str = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

public:
    string intToRoman(int num) {
        string ans = "";

        for (int i = 0; i < value.size(); i++) {
            if (num < value[i]) continue;
            int k = num / value[i];
            num -= k * value[i];

            while (k--) {
                ans += str[i];
            }
        }

        return ans;
    }
};