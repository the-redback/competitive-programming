#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <tuple>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        set<int> setX, setY;
        for (auto& p : points) {
            setX.insert(p[0]);
            setY.insert(p[1]);
        }

        if (setX.size() == points.size() || setY.size() == points.size()) return 0;

        map<int, vector<int>> p;  // we need sorted map for remembering lastx
        unordered_map<int, unordered_map<int, int>> lastx;

        for (auto point : points) {
            p[point[0]].push_back(point[1]);
        }

        int result = INT_MAX;

        for (auto xs : p) {
            auto& ys = xs.second;
            int x1 = xs.first;
            sort(ys.begin(), ys.end());

            for (int i = 0; i < ys.size(); i++) {
                int y1 = ys[i];
                for (int j = i + 1; j < ys.size(); j++) {
                    int y2 = ys[j];

                    if (lastx[y1].find(y2) != lastx[y1].end()) {
                        auto x2 = lastx[y1][y2];
                        int area = abs((x2 - x1) * (y2 - y1));
                        result = min(result, area);
                    }
                    lastx[y1][y2] = x1;
                }
            }
        }

        if (result == INT_MAX) return 0;

        return result;
    }
};

static bool _foo = ios::sync_with_stdio(false);
static ostream* _bar = cin.tie(NULL);
