#include <bits/stdc++.h>
using namespace std;
int main() {
    int i, j, a = 0, b = 0, n, m, k;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        if (k == -1)
            a++;
        else
            b++;
    }
    while (m--) {
        scanf("%d %d", &i, &j);
        i = j - i + 1;
        j = ceil(i / 2.0);
        if (j <= a && j <= b && i % 2 == 0)
            printf("1\n");
        else
            printf("0\n");
    }
    return 0;
}
