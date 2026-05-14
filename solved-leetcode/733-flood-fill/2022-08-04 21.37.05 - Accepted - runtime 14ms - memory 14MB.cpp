class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        rec(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }

    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {-1, 0, 1, 0};

    void rec(vector<vector<int>>& image, int r, int c, int newColor, int color) {
        image[r][c] = newColor;
        for (int i = 0; i < 4; i++) {
            int xx = r + dx[i];
            int yy = c + dy[i];

            if (xx < 0 || yy < 0 || xx >= image.size() || yy >= image[0].size() || image[xx][yy] != color) continue;
            rec(image, xx, yy, newColor, color);
        }
    }
};