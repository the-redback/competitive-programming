#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int> &nums, int left, int right) {
    int pivot = nums[right];

    int l = left;
    for (int i = left; i < right; i++) {
        if (nums[i] < pivot) {
            swap(nums[l], nums[i]);
            l++;
        }
    }
    swap(nums[l], nums[right]);

    return l;
}

void quickSort(vector<int> &nums, int left, int right) {
    if (left >= right) {
        return;
    }

    int pivotIndex = partition(nums, left, right);

    quickSort(nums, left, pivotIndex - 1);
    quickSort(nums, pivotIndex + 1, right);
}


int main() {
    // Quick Sort
    vector<int> nums = {10, 7, 8, 9, 1, 5};
    quickSort(nums, 0, nums.size() - 1);
    cout << "Sorted array:\n";
    for (int num: nums) {
        cout << num << " ";
    }
    cout << '\n';
    return 0;
}
