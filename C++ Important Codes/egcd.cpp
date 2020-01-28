int sii, si, tii, ti; // ii=i-1, i=i, s/t=i+1
int egcd(int a, int b) {
    int r, q, s, t;
    sii = 1, si = 0;
    tii = 0, ti = 1;
    while (b > 0) {
        q = a / b;
        r = a % b;
        s = sii - (q * si);
        t = tii - (q * ti);
        sii = si, si = s;
        tii = ti, ti = t;
        a = b, b = r;
    }
    return a; //  return a, sii, tii
}
