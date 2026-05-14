#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;

        for (int left = 0, right = height.size() - 1; left < right;) {
            int width = right - left;
            area = max(area, min(height[left], height[right]) * width);

            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return area;
    }
};