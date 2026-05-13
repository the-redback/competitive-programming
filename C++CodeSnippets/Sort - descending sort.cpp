#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool comp(int a, int b) { return a > b; }

int main() {
    vector<int> nums = {5, 1, 4, 2, 3};
    sort(nums.begin(), nums.end(), comp);

    for (int num : nums) {
        cout << num << " ";
    }
    cout << '\n';
    return 0;
}
