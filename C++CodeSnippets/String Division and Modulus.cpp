long long div(char a[], long long n, char c[]) {
    int i, j, t = 0, l, d = 0, r = 0;
    long long rem = 0;
    l = strlen(a);
    for (i = 0; i < l; i++) {
        rem = (rem * 10) + a[i] - 48;

        if (rem >= n || r != 0) {
            j = rem / n;
            rem = rem % n;
            c[d] = j + 48;
            d++;
            r = 1;
        }
    }
    if (d == 0) {
        c[d] = '0';
        d++;
    }
    c[d] = '\0';
    return rem;
}