class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int ans = 0;
        int cnt = 0;
        int last = 0;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] != 1) continue;
            if (cnt == 0)
                ans = i;
            else {
                ans = max(ans, (i - last) / 2);
            }
            last = i;
            cnt++;
        }

        ans = max(ans, (int)seats.size() - 1 - last);
        return ans;
    }
};