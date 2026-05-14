#include <vector>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        int currLength = 0;
        int lastPos = 0;
        for (int i = 0; i < words.size(); i++) {
            if (currLength + words[i].size() + (i - lastPos) <= maxWidth) {
                currLength += words[i].size();
                continue;
            }

            ans.push_back(constructLine(words, maxWidth, lastPos, i - 1, currLength, false));
            lastPos = i;
            currLength = words[i].size();
        }

        ans.push_back(constructLine(words, maxWidth, lastPos, words.size() - 1, currLength, true));

        return ans;
    }

    string constructLine(vector<string>& words, int maxWidth, int left, int right, int currLength, bool leftJustify) {
        string s;
        int each, rem;

        if (left == right) {
            leftJustify = true;
        } else {
            int surplus = maxWidth - currLength;
            each = surplus / (right - left);
            rem = surplus % (right - left);
        }

        for (int i = left; i <= right; i++) {
            s += words[i];

            if (leftJustify) {
                if (s.size() < maxWidth) s += " ";
                continue;
            }

            for (int j = 0; i != right && j < each; j++) s += " ";
            if (rem) {
                s += " ";
                rem--;
            }
        }
        while (s.size() < maxWidth) {
            s += " ";
        }

        return s;
    }
};