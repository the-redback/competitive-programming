/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */

#include <cmath>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
    double x, y;

    Point() {}
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }
};

vector<Point> points, hull;
Point pivot;

Point makeVector(Point a, Point b) {
    return Point(b.x - a.x, b.y - a.y);
}

double crossProduct(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

double magnitude(Point a) {
    return sqrt(a.x * a.x + a.y * a.y);
}

bool compare(Point a, Point b) {
    double cross = crossProduct(makeVector(pivot, a), makeVector(pivot, b));

    if (cross != 0) {
        return cross > 0;
    }

    return magnitude(makeVector(pivot, a)) < magnitude(makeVector(pivot, b));
}

void findPivot() {
    pivot = points[0];

    for (Point p : points) {
        if (p.x < pivot.x || (p.x == pivot.x && p.y < pivot.y)) {
            pivot = p;
        }
    }
}

void convexHull() {
    findPivot();

    sort(points.begin(), points.end(), compare);

    hull.clear();

    hull.push_back(points[0]);
    hull.push_back(points[1]);

    for (int i = 2; i < points.size(); i++) {
        while (hull.size() >= 2) {
            int n = hull.size();

            double cross = crossProduct(makeVector(hull[n - 2], hull[n - 1]),
                                        makeVector(hull[n - 2], points[i]));

            if (cross <= 0) {
                hull.pop_back();
            } else {
                break;
            }
        }

        hull.push_back(points[i]);
    }
}

int main() {
    int n;
    cin >> n;

    points.clear();

    for (int i = 0; i < n; i++) {
        double x, y;
        cin >> x >> y;

        points.push_back(Point(x, y));
    }

    convexHull();

    for (Point p : hull) {
        cout << p.x << " " << p.y << '\n';
    }

    return 0;
}

/*
Sample Input;
5
0 0
2 0
2 2
1 1
0 2

Output:
0 0
2 0
2 2
0 2
*/