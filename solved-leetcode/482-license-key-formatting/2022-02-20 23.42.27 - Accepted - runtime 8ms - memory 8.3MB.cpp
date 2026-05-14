#include <string>
#include <cmath>
#include <cctype>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int cnt = 0;
        int n = s.size();
        for (auto ch : s) {
            if (ch != '-') cnt++;
        }

        int rem = cnt % k;
        int t_cnt = ceil(cnt / (k * 1.0));

        string str = "";
        cnt = 0;

        for (auto ch : s) {
            if (ch == '-') continue;
            str += toUppercase(ch);
            cnt++;
            if (rem != 0 && cnt == rem && t_cnt > 1) {
                str += '-';
                rem = 0;
                cnt = 0;
                t_cnt--;
            } else if (cnt == k && t_cnt > 1) {
                str += '-';
                cnt = 0;
                t_cnt--;
            }
        }
        return str;
    }

    bool isalnum(char ch) {
        if (ch >= '0' && ch <= '9') return true;
        if (ch >= 'A' && ch <= 'Z') return true;
        if (ch >= 'a' && ch <= 'z') return true;
        return false;
    }

    char toUppercase(char ch) {
        if (ch >= 'a' && ch <= 'z') return ch - 'a' + 'A';
        return ch;
    }
};