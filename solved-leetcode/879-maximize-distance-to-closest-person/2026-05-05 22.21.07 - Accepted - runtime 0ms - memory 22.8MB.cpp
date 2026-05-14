#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        int ans = 0;
        int left = -1;
        int counter = 0;

        for (int i = 0; i < n; i++) {
            if (seats[i] == 1) {
                counter = 0;
                left = i;
            } else {
                counter++;
            }

            if (left == -1) ans = max(ans, i + 1);

            ans = max(ans, (counter + 1) / 2);
        }

        if (left != -1) ans = max(ans, n - left - 1);

        return ans;
    }
};