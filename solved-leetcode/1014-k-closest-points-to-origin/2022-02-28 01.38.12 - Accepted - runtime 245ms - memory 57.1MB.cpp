class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int low = 0, high = points.size() - 1;
        k--;
        while (low < high) {
            int index = partition(points, low, high);
            cout << index << " ";
            if (index == k) {
                break;
            }
            if (index < k) {
                low = index + 1;
            } else
                high = index - 1;
        }
        return vector<vector<int>>(points.begin(), points.begin() + k + 1);
    }

    int partition(vector<vector<int>>& points, int left, int right) {
        int pivot = left + (right - left) / 2;
        points[pivot].swap(points[right]);

        int dist = distance(points[right]);

        for (int i = left; i < right; i++) {
            if (distance(points[i]) <= dist) {
                points[i].swap(points[left]);
                left++;
            }
        }
        points[right].swap(points[left]);
        return left;
    }

    int distance(vector<int>& point) { return point[0] * point[0] + point[1] * point[1]; }
};

// Binary search