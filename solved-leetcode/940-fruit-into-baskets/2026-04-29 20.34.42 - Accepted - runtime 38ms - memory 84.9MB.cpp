#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int left = 0, right = 0;
        int result = 0;

        while (right < fruits.size()) {
            mp[fruits[right]]++;

            while (mp.size() > 2) {
                mp[fruits[left]]--;

                if (mp[fruits[left]] == 0) mp.erase(fruits[left]);
                left++;
            }

            result = max(result, right - left + 1);
            right++;
        }

        return result;
    }
};