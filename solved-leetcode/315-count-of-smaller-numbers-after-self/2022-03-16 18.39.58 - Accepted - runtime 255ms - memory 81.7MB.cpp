#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstring>

using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int>> v;
        MaxVal = nums.size();
        tree[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            tree[i + 1] = 0;
            v.push_back({nums[i], i + 1});
        }
        // memset(tree, 0, sizeof(tree));

        sort(v.begin(), v.end());
        vector<int> ans(nums.size(), 0);

        for (auto a : v) {
            ans[a.second - 1] = query(a.second);
            update(1, 1);
            update(a.second + 1, -1);
        }
        return ans;
    }

    int MaxVal;
    int tree[100010];

    void update(int idx, int val) {
        while (idx <= MaxVal) {
            tree[idx] += val;
            idx += idx & (-idx);
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }
};

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);