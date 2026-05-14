#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int zero = 0;
        int one = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '0') zero++;
        int ans = zero;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0')
                zero--;
            else if (s[i] == '1')
                one++;
            ans = min(ans, zero + one);
        }
        return ans;
    }
};