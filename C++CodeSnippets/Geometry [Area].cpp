double polygonArea(vector<Point>& polygon) {
    double area = 0;

    for (int i = 0; i < polygon.size(); i++) {
        int j = (i + 1) % polygon.size();

        area += polygon[i].x * polygon[j].y - polygon[j].x * polygon[i].y;
    }

    return abs(area) / 2.0;
}

double triangleArea(Point a, Point b, Point c) {
    return abs(crossProduct(makeVector(a, b), makeVector(a, c))) / 2.0;
}