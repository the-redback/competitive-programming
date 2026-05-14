class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> start, end;
        for (auto interval : intervals) {
            start.push_back(interval[0]);
            end.push_back(interval[1]);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int room = 0;
        int si = 0, ei = 0;
        while (si < start.size()) {
            if (start[si] >= end[ei])
                ei++;
            else
                room++;
            si++;
        }
        return room;
    }
};