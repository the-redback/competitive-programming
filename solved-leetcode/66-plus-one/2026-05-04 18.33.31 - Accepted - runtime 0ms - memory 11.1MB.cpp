#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int hand = 1;

        int i;
        for (i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                result.push_back(digits[i] + 1);
                break;
            }
            result.push_back(0);
        }

        for (int j = i - 1; j >= 0; j--) {
            result.push_back(digits[j]);
        }

        if (result.back() == 0) {
            result.push_back(1);
        }
        reverse(result.begin(), result.end());

        return result;
    }
};