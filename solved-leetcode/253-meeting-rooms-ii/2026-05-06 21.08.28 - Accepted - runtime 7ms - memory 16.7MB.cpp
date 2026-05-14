class Solution {
public:
    static bool comp(vector<int>& v1, vector<int>& v2) { return v1[0] < v2[0]; }

    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        priority_queue<int, vector<int>, greater<int>> pq;

        int rooms = 0;
        for (auto interval : intervals) {
            if (!pq.empty() && pq.top() <= interval[0]) pq.pop();
            pq.push(interval[1]);
            rooms = max(rooms, (int)pq.size());
        }

        return rooms;
    }
};