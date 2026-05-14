#include <map>
using namespace std;

class Robot {
public:
    bool move();
    void turnLeft();
    void turnRight();
    void clean();
};


/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the
 * cell.
 *     // Returns false if the cell in front is blocked and robot stays in the
 * current cell. bool move();
 *
 *     // Robot will stay in the same cell after calling turnLeft/turnRight.
 *     // Each turn will be 90 degrees.
 *     void turnLeft();
 *     void turnRight();
 *
 *     // Clean the current cell.
 *     void clean();
 * };
 */

class Solution {
public:
    map<pair<int, int>, bool> visited;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    void goback(Robot& robot) {
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }

    void dfs(Robot& robot, int x, int y, int dir) {
        visited[{x, y}] = true;
        robot.clean();

        for (int i = 0; i < 4; i++) {
            int in = (dir + i) % 4;

            int xx = x + dx[in];
            int yy = y + dy[in];

            if (visited.find({xx, yy}) == visited.end() && robot.move()) {
                dfs(robot, xx, yy, in);
                goback(robot);
            }
            robot.turnRight();
        }
        return;
    }

    void cleanRoom(Robot& robot) { dfs(robot, 0, 0, 0); }
};