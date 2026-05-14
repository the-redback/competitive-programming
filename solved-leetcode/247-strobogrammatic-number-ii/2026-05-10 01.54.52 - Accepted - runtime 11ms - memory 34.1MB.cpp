#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char, char> sub_numbers;
    int N;

    vector<string> rec(int n) {
        if (n == 0) return {""};
        if (n == 1) return {"0", "1", "8"};

        auto mid_words = rec(n - 2);

        vector<string> words;
        for (auto w : mid_words) {
            for (auto [pre, post] : sub_numbers) {
                if (n == N && pre == '0') continue;

                words.push_back(pre + w + post);
            }
        }

        return words;
    }

    vector<string> findStrobogrammatic(int n) {
        sub_numbers['0'] = '0';
        sub_numbers['1'] = '1';
        sub_numbers['6'] = '9';
        sub_numbers['8'] = '8';
        sub_numbers['9'] = '6';
        N = n;
        return rec(n);
    }
};