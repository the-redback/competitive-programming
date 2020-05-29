#define NN 47000

bool p[NN + 7];   // Hashing
vector<int> pr;   // storing prime
void sieve(int n) {
    int i, j, k, l;
    p[1] = 1;
    pr.push_back(2);
    for (i = 4; i <= n; i += 2) p[i] = 1;
    for (i = 3; i <= n; i += 2) {
        if (p[i] == 0) {
            pr.push_back(i);
            for (j = i * i; j <= n; j += 2 * i) p[j] = 1;
        }
    }
}

int factor(int n) {
    int count, k, i;
    for (i = 0; i < pr.size() && pr[i] * pr[i] <= n; i++) {
        k = pr[i];
        count = 0;
        while (n % k == 0) {
            n /= k;
            count++;
        }
        if (n == 1) break;
    }
    if (n > 1) then, n is another prime factor;
}