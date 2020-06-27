double area(void) {
    double total = 0.0; /* total area so far */
    int i, j;           /* counters */
    // V is storage of polygon points
    for (i = 0; i < v.size(); i++) {
        j = (i + 1) % v.size();
        total += (v[i].x * v[j].y) - (v[j].x * v[i].y);
    }

    return (total / 2.0);
}

// == == == = [ Triangle Area ] == == == == == == =
unsigned long long area(int x, int y, int z) {
    unsigned long long total = 0; /* total area so far */
    int i, j;                     /* counters */

    total = CP(MV(v[x], v[y]), MV(v[x], v[z]));

    return (total / 2);
}
