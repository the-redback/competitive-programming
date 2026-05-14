#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.size() == 0 || heights[0].size() == 0) return {};

        grid = heights;
        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> atlanticvisited = vector<vector<bool>>(rows, vector<bool>(cols));
        vector<vector<bool>> pacificvisited = vector<vector<bool>>(rows, vector<bool>(cols));

        queue<pair<int, int>> atlantic, pacific;

        for (int i = 0; i < rows; i++) {
            pacific.push({i, 0});
            atlantic.push({i, cols - 1});
        }

        for (int i = 0; i < cols; i++) {
            pacific.push({0, i});
            atlantic.push({rows - 1, i});
        }

        dfs(atlantic, atlanticvisited);
        dfs(pacific, pacificvisited);

        vector<vector<int>> result;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (atlanticvisited[i][j] && pacificvisited[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

    vector<vector<int>> grid;
    int rows;
    int cols;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};

    void dfs(queue<pair<int, int>>& q, vector<vector<bool>>& visited) {
        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            visited[node.first][node.second] = true;

            for (int i = 0; i < 4; i++) {
                int x = node.first + dx[i];
                int y = node.second + dy[i];

                if (x < 0 || y < 0 || x >= rows || y >= cols || visited[x][y] ||
                    grid[x][y] < grid[node.first][node.second]) {
                    continue;
                }

                q.push({x, y});
            }
        }
    }
};