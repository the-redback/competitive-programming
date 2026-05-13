#include <iostream>
#include <vector>
#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &nums, int left, int mid, int right) {
    vector<int> temp;

    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp.push_back(nums[i++]);
        } else {
            temp.push_back(nums[j++]);
        }
    }

    while (i <= mid) {
        temp.push_back(nums[i++]);
    }

    while (j <= right) {
        temp.push_back(nums[j++]);
    }

    for (int k = 0; k < temp.size(); k++) {
        nums[left + k] = temp[k];
    }
    return;
}

void mergeSort(vector<int> &nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;

    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);

    merge(nums, left, mid, right);
}

int main() {
    vector<int> nums = {12, 11, 13, 5, 6, 7};

    mergeSort(nums, 0, nums.size() - 1);

    for (int num: nums) {
        cout << num << " ";
    }
    cout << '\n';
    return 0;
}
