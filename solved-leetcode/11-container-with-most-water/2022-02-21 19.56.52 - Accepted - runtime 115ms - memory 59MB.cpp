class Solution {
public:
    int maxArea(vector<int>& height) {
        int sum = 0;
        for (int i = 0, j = height.size() - 1; i <= j;) {
            sum = max(sum, (j - i) * min(height[i], height[j]));
            if (height[i] < height[j])
                i++;
            else
                j--;
        }
        return sum;
    }
};