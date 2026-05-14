#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

class DetectSquares {
    unordered_map<int, unordered_map<int, int>> m;

public:
    DetectSquares() {}

    void add(vector<int> point) { m[point[0]][point[1]]++; }

    int count(vector<int> point) {
        int ans = 0;
        int x = point[0];
        int y = point[1];

        for (auto it : m[x]) {
            int yy = it.first;
            if (y == yy) continue;
            int len = abs(yy - y);

            if (x + len <= 1000) ans += m[x + len][y] * m[x + len][yy] * m[x][yy];
            if (x - len >= 0) ans += m[x - len][y] * m[x - len][yy] * m[x][yy];
        }

        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */