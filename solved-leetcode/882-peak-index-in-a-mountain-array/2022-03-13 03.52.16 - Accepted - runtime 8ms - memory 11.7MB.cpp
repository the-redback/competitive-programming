#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0;
        int high = arr.size() - 1;

        while (high - low > 3) {
            int mid1 = low + (high - low) / 3;
            int mid2 = high - (high - low) / 3;

            if (arr[mid1] > arr[mid2])
                high = mid2;
            else
                low = mid1;
        }

        for (int i = low + 1; i <= high - 1; i++) {
            if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1]) return i;
        }
        return low;
    }
};

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);