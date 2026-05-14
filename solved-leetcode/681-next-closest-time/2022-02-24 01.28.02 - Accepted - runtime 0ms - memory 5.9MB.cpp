#include <string>
using namespace std;

class Solution {
public:
    string nextClosestTime(string time) {
        string res = time.substr(0, 2);
        res += time.substr(3, 2);
        sort(res.begin(), res.end());

        for (int i = time.size() - 1; i >= 0; i--) {
            if (i == 2) continue;  //':'

            int in = upper_bound(res.begin(), res.end(), time[i]) - res.begin();  // immediate bigger number
            if (in < 4) {
                time[i] = res[in];
                if (i >= 3 && (time[3] <= '5' && time[4] <= '9')) return time;
                if (i < 2 && ((time[0] == '2' && time[1] <= '3') || (time[0] <= '1' && time[1] <= '9'))) return time;
            }
            time[i] = res[0];
        }
        return time;
    }
};