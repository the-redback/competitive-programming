#include <queue>
using namespace std;

class Solution {
private:
    static bool comp(const vector<int> v1, const vector<int> v2) { return v1[0] < v2[0]; }

public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        priority_queue<int, vector<int>, greater<int>> pq;

        int room = 0;
        // pq.push(intervals[0][1]);
        for (auto interval : intervals) {
            if (!pq.empty() && pq.top() <= interval[0]) pq.pop();
            pq.push(interval[1]);
            room = max(room, (int)pq.size());
        }
        return room;
    }
};