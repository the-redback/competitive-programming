#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <vector>
using namespace std;
#define mem(x, y) memset(x, y, sizeof(x));

int dp[1000];
bool dc[1000];
vector<int> v;
int LDS(int u) {
    if (dc[u])
        return dp[u];
    int max = 0;
    for (int i = u + 1; i < v.size(); i++) {
        if (v[i] <= v[u]) {
            if (max < LDS(i)) {
                max = LDS(i);
            }
        }
    }
    dp[u] = max + 1;
    dc[u] = 1;
    return dp[u];
}

main() {
    int i = 0, k, n, j;
    while (scanf("%d", &n) == 1) {
        if (n == -1)
            return 0;
        i++;
        mem(dc, 0);
        v.clear();
        v.push_back(n);
        while (1) {
            scanf("%d", &n);
            if (n == -1)
                break;
            v.push_back(n);
        }
        k = 0;
        for (j = 0; j < v.size(); j++) {
            if (k < LDS(j)) {
                k = LDS(j);
            }
        }
        if (i != 1)
            puts("");
        printf("Test #%d:\n  maximum possible interceptions: %d\n", i, k);
    }
}
