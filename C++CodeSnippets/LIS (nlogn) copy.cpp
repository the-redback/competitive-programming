#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
vector<int> lisLength;
vector<int> lis;

int LIS() {
    lis.clear();
    lisLength.assign(nums.size(), 1);

    lis.push_back(INT_MIN);

    for (int i = 0; i < nums.size(); i++) {

        int low = 0;
        int high = lis.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[i] > lis[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (low == lis.size()) {
            lis.push_back(nums[i]);
        } else {
            lis[low] = nums[i];
        }
        lisLength[i] = low;
    }
    return lis.size() - 1;
}

vector<int> buildLIS() {
    vector<int> sequence;

    int len = 0;
    int idx = 0;

    for (int i = 0; i < lisLength.size(); i++) {
        if (lisLength[i] > len) {
            len = lisLength[i];
            idx = i;
        }
    }
    sequence.push_back(nums[idx]);

    for (int i = idx - 1; i >= 0; i--) {
        if (nums[i] < nums[idx] &&
            lisLength[i] == lisLength[idx] - 1) {

            sequence.push_back(nums[i]);
            idx = i;
        }
    }
    reverse(sequence.begin(), sequence.end());
    return sequence;
}

int main() {
    nums = {1, 7, 3, 5, 9, 4, 8};
    int length = LIS();

    cout << "LIS Length: " << length << '\n';
    vector<int> sequence = buildLIS();
    for (int num : sequence) {
        cout << num << " ";
    }
    cout << '\n';
    return 0;
}