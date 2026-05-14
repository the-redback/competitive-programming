#include <vector>
#include <queue>
#include <cmath>

using namespace std;

class Solution {
public:
    int racecar(int target) {
        queue<vector<int>> q;
        q.push({0, 0, 1});  // moves, position, speed

        while (!q.empty()) {
            auto item = q.front();
            q.pop();

            int moves = item[0];
            int pos = item[1];
            int speed = item[2];

            if (pos == target) return moves;

            if (abs(pos) > 2 * target) continue;

            q.push({moves + 1, pos + speed, speed * 2});

            if (pos + speed > target && speed > 0 || pos + speed < target && speed < 0) {
                if (speed < 0)
                    q.push({moves + 1, pos, 1});
                else
                    q.push({moves + 1, pos, -1});
            }
        }
        return 0;
    }
};