class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int n = nums1.size();
        int m = nums2.size();

        int low = 0, high = n;
        int half = (n + m + 1) / 2;

        while (low <= high) {
            int partitionA = (high + low) / 2;
            int partitionB = half - partitionA;

            int maxLeftA = (partitionA > 0) ? nums1[partitionA - 1] : INT_MIN;
            int maxLeftB = (partitionB > 0) ? nums2[partitionB - 1] : INT_MIN;
            int minRightA = (partitionA < n) ? nums1[partitionA] : INT_MAX;
            int minRightB = (partitionB < m) ? nums2[partitionB] : INT_MAX;

            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {
                if ((n + m) % 2) {
                    return max(maxLeftA, maxLeftB);
                } else {
                    return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
                }
            } else if (maxLeftA > minRightB) {
                high = partitionA - 1;
            } else {
                low = partitionA + 1;
            }
        }
        return 0;
    }
};