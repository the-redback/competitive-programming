#include <map>
using namespace std;

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<bool> higher(n), lower(n);
        map<int, int> mp;

        mp[arr[n - 1]] = n - 1;
        higher[n - 1] = true;
        lower[n - 1] = true;
        int ans = 1;
        for (int i = n - 2; i >= 0; i--) {
            auto high = mp.lower_bound(arr[i]);
            auto low = mp.upper_bound(arr[i]);  // upper_bound so that we can look for previous value;

            if (high != mp.end()) higher[i] = lower[high->second];
            if (low != mp.begin()) {
                --low;  // less or equal to arr[i]
                lower[i] = higher[low->second];
            }

            if (higher[i]) ans++;
            mp[arr[i]] = i;
        }
        return ans;
    }
};