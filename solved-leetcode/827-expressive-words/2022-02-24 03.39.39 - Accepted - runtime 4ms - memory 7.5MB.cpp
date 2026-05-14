#include <vector>

using namespace std;

class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        vector<int> nums(1, 1);
        string str = "";
        str += s[0];
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i])
                nums[nums.size() - 1]++;
            else {
                str += s[i];
                nums.push_back(1);
            }
        }

        int ans = 0;
        for (string ss : words) {
            int cnt = 0;
            int l = 0;
            for (int i = 0; i < ss.size() && l < str.size(); i++) {
                cnt++;
                if (i + 1 != ss.size() && ss[i] == ss[i + 1]) continue;
                if (ss[i] != str[l] || nums[l] < cnt || (cnt != nums[l] && nums[l] < 3)) break;
                cnt = 0;
                if (i + 1 == ss.size() && l + 1 == str.size()) ans++;
                l++;
            }
        }

        return ans;
    }
};