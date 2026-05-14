#include <vector>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26] = {0};

        for (auto ch : tasks) {
            freq[ch - 'A']++;
        }

        sort(freq, freq + 26);
        int f_max = freq[25];
        int idle_time = (f_max - 1) * n;

        for (int i = 24; i >= 0 && idle_time > 0; i--) {
            idle_time -= min(f_max - 1, freq[i]);
        }

        idle_time = max(0, idle_time);

        return tasks.size() + idle_time;
    }
};