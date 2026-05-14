#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string nextClosestTime(string time) {
        vector<int> digits;
        for (auto ch : time) {
            if (ch == ':') continue;
            digits.push_back(ch - '0');
        }

        int curr = (digits[0] * 10 + digits[1]) * 60 + (digits[2] * 10 + digits[3]);
        int minDiff = INT_MAX;
        int bestT = curr;

        for (int h1 : digits) {
            for (int h2 : digits) {
                int hour = h1 * 10 + h2;
                if (hour >= 24) continue;

                for (int m1 : digits) {
                    for (int m2 : digits) {
                        int minute = m1 * 10 + m2;
                        if (minute >= 60) continue;

                        int total = hour * 60 + minute;
                        int diff = (total - curr + 1440) % 1440;  // 60 * 24 = 1440

                        if (diff != 0 && diff < minDiff) {
                            minDiff = diff;
                            bestT = total;
                        }
                    }
                }
            }
        }

        int h = bestT / 60;
        int m = bestT % 60;

        string ans = (h < 10 ? "0" : "") + to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m);
        return ans;
    }
};