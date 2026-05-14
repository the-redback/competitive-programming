#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mapt, maps;

        for (auto ch : t) mapt[ch]++;

        int str_length = INT_MAX;
        int index;
        int left = 0;
        int counter = 0;

        for (int right = 0; right < s.size(); right++) {
            if (mapt.find(s[right]) == mapt.end()) continue;
            maps[s[right]]++;
            if (maps[s[right]] == mapt[s[right]]) counter++;

            while (counter == mapt.size() && left <= right) {
                if (mapt.find(s[left]) == mapt.end()) {
                    left++;
                    continue;
                }

                if (str_length > right - left + 1) {
                    str_length = right - left + 1;
                    index = left;
                    cout << str_length << "\n";
                }

                maps[s[left]]--;

                if (maps[s[left]] < mapt[s[left]]) counter--;

                left++;
            }
        }

        if (str_length == INT_MAX) return "";
        return s.substr(index, str_length);
    }
};
