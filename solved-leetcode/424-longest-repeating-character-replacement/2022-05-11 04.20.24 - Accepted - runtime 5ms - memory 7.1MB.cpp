#include <vector>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counts(26, 0);
        int start = 0;
        int maxcount = 0;
        int answer = 0;

        for (int i = 0; i < s.size(); i++) {
            counts[s[i] - 'A']++;
            maxcount = max(maxcount, counts[s[i] - 'A']);
            while (i - start + 1 - maxcount > k) {
                counts[s[start] - 'A']--;
                start++;
            }

            answer = max(answer, i - start + 1);
        }

        return answer;
    }
};
