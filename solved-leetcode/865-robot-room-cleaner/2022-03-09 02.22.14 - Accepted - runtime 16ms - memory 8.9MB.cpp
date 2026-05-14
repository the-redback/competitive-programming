/**
 * // This is the robot's control interface.
 * // You should not implement it, or speculate about its implementation
 * class Robot {
 *   public:
 *     // Returns true if the cell in front is open and robot moves into the cell.
 *     // Returns false if the cell in front is blocked and robot stays in the current cell.
 *     bool move();
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
    void cleanRoom(Robot& robot) { dfs(robot, 0, 0, 0); }

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

    void dfs(Robot& robot, int r, int c, int dir) {
        visited[{r, c}] = true;

        robot.clean();
        for (int i = 0; i < 4; i++) {
            int in = (dir + i) % 4;
            int x = r + dx[in];
            int y = c + dy[in];

            if (!visited[{x, y}] && robot.move()) {
                dfs(robot, x, y, in);
                goback(robot);
            }
            robot.turnRight();
        }
        return;
    }
};

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);