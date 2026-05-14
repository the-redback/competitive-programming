#include <string>
using namespace std;

class Solution {
public:
    int largestVariance(string s) {
        int ans = 0;
        for (char hfreq = 'a'; hfreq <= 'z'; ++hfreq) {
            for (char lfreq = 'a'; lfreq <= 'z'; ++lfreq) {
                if (hfreq == lfreq) continue;

                int hcount = 0;
                int lcount = 0;
                bool has_b = false;

                for (auto ch : s) {
                    if (ch == hfreq) hcount++;
                    if (ch == lfreq) lcount++;

                    if (lcount > 0)
                        ans = max(ans, hcount - lcount);
                    else if (has_b)  // consider last lfreq before resetting 0.
                        ans = max(ans, hcount - 1);

                    if (lcount > hcount) {
                        // reset
                        lcount = 0;
                        hcount = 0;
                        has_b = true;
                    }
                }
            }
        }
        return ans;
    }
};