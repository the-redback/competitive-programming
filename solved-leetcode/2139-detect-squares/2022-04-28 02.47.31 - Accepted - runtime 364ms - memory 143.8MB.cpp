class DetectSquares {
    int m[1001][1001] = {};

public:
    DetectSquares() {}

    void add(vector<int> point) { m[point[0]][point[1]]++; }

    int count(vector<int> point) {
        int ans = 0;
        int x = point[0];
        int y = point[1];

        for (int xx = 0; xx <= 1000; xx++) {
            if (x == xx || m[xx][y] == 0) continue;
            int len = abs(xx - x);

            if (y + len <= 1000) ans += m[x][y + len] * m[xx][y + len] * m[xx][y];
            if (y - len >= 0) ans += m[x][y - len] * m[xx][y - len] * m[xx][y];
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