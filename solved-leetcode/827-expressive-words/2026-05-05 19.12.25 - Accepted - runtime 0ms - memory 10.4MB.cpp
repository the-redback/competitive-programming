class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        vector<pair<char, int>> nums;
        nums.push_back({s[0], 1});

        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i])
                nums[nums.size() - 1].second += 1;
            else
                nums.push_back({s[i], 1});
        }

        int result = 0;
        for (string w : words) {
            int counter = 1;
            int k = 0;

            for (int i = 1; i <= w.size() && k < nums.size(); i++) {
                if (i != w.size() && w[i - 1] == w[i]) {
                    counter++;
                    continue;
                }

                pair<char, int> p = nums[k];
                char ch = w[i - 1];

                if (p.first != ch || p.second < counter || (p.second > counter && p.second < 3)) break;

                if (i == w.size() && k + 1 == nums.size()) result++;
                counter = 1;
                k++;
            }
        }

        return result;
    }
};