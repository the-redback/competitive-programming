class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int flip = 0;
        int one = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                one++;
            else if (s[i] == '0') {
                flip++;
                flip = min(one, flip);
            }
        }
        return flip;
    }
};