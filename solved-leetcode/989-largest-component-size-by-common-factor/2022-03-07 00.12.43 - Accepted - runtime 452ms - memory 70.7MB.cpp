#include <map>
using namespace std;

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int maxx = *max_element(nums.begin(), nums.end());
        root = vector<int>(maxx + 1);
        for (int i = 0; i < root.size(); i++) root[i] = i;

        map<int, int> mp;  // num, first prime divisor
        for (auto num : nums) {
            int k = 2;
            int last = -1;
            while (k * k <= num) {
                if (num % k == 0) {
                    if (last == -1) {
                        last = k;
                        mp[num] = k;
                    } else {
                        Union(last, k);
                        last = k;
                    }
                    while (num % k == 0) num /= k;
                }
                k++;
            }
            if (num != 1) {
                if (last == -1)
                    mp[num] = num;
                else
                    Union(last, num);
            }
        }

        map<int, int> count;
        int ans = 0;
        for (auto num : nums) {
            int u = find(mp[num]);
            count[u]++;
            ans = max(ans, count[u]);
        }

        return ans;
    }

    vector<int> root;

private:
    int find(int u) {
        if (u != root[u]) root[u] = find(root[u]);
        return root[u];
    }

    void Union(int a, int b) {
        int u = find(a);
        int v = find(b);

        root[v] = u;
        return;
    }
};
