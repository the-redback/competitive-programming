class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<bool> odd_jump(n), even_jump(n);

        map<int, int> mp;

        mp[arr[n - 1]] = n - 1;
        odd_jump[n - 1] = true;
        even_jump[n - 1] = true;
        int result = 1;

        for (int i = n - 2; i >= 0; i--) {
            auto high = mp.lower_bound(arr[i]);
            auto low = mp.upper_bound(arr[i]);

            if (high != mp.end()) odd_jump[i] = even_jump[high->second];

            if (low != mp.begin()) {
                low--;
                even_jump[i] = odd_jump[low->second];
            }

            if (odd_jump[i]) result++;
            mp[arr[i]] = i;
        }

        return result;
    }
};