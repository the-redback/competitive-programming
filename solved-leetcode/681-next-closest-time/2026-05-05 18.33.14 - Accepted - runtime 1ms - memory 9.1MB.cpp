class Solution {
public:
    string nextClosestTime(string time) {
        unordered_set<int> digits;
        for (auto ch : time) {
            if (ch == ':') continue;
            digits.insert(ch);
        }

        int minutes = ((time[0] - '0') * 10 + (time[1] - '0')) * 60 + ((time[3] - '0') * 10 + (time[4] - '0'));

        while (true) {
            minutes = (minutes + 1) % 1440;  // 60 * 24 = 1440

            int h = minutes / 60;
            int m = minutes % 60;

            string s = (h < 10 ? "0" : "") + to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m);

            bool valid = true;
            for (auto ch : s) {
                if (ch != ':' && digits.find(ch) == digits.end()) {
                    valid = false;
                    break;
                }
            }

            if (valid) return s;
        }
    }
};