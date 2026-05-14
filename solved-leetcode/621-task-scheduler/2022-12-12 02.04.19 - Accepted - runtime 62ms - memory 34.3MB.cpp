#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};

        int f_max = 0;

        for (auto ch : tasks) {
            freq[ch - 'A']++;
            f_max = max(f_max, freq[ch - 'A']);
        }

        int n_max = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] == f_max) n_max++;
        }

        int slots = (f_max - 1) * (n + 1) + n_max;

        return max((int)tasks.size(), slots);
    }
};