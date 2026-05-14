#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int n1 = nums1.size(), n2 = nums2.size();

        int low = 0, high = n1, half = (n1 + n2 + 1) / 2;
        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = half - cut1;

            if (cut1 < n1 && nums2[cut2 - 1] > nums1[cut1])
                low = cut1 + 1;
            else if (cut1 > 0 && nums1[cut1 - 1] > nums2[cut2])
                high = cut1 - 1;
            else {
                int maxOfLeft = INT_MIN;
                if (cut1 == 0)
                    maxOfLeft = nums2[cut2 - 1];
                else if (cut2 == 0)
                    maxOfLeft = nums1[cut1 - 1];
                else
                    maxOfLeft = max(nums1[cut1 - 1], nums2[cut2 - 1]);

                if ((n1 + n2) % 2) return maxOfLeft;

                int minOfRight = INT_MAX;
                if (cut1 == n1)
                    minOfRight = nums2[cut2];
                else if (cut2 == n2)
                    minOfRight = nums1[cut1];
                else
                    minOfRight = min(nums1[cut1], nums2[cut2]);

                return (maxOfLeft + minOfRight) / 2.0;
            }
        }
        return 0.0;
    }
};