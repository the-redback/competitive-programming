/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */

#include <bits/stdc++.h>
char a[200][200];
int N, M;
int dirx[] = {-1, 0, 0, 1};
int diry[] = {0, -1, 1, 0};

int call(int i, int j) {
    int sum = 1;
    if (i < 0 || j < 0 || i >= N || j >= M) return 0;
    if (a[i][j] == '#') return 0;
    a[i][j] = '#';
    for (int k = 0; k < 4; k++) {
        sum += call(i + dirx[k], j + diry[k]);
    }
    return sum;
}

main() {
    int tc, flag = 0, i, j, k, sum;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d%d", &M, &N);
        getchar();
        for (i = 0; i < N; i++) {
            gets(a[i]);
        }
        sum = 0;
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) {
                if (a[i][j] == '@') sum = call(i, j);
            }
        }
        printf("Case %d: %d\n", ++flag, sum);
    }
    return 0;
}
