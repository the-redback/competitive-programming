#include <bits/stdc++.h>
using namespace std;
main() {
    char a[30];
    int i, j, k, l;
    while (gets(a)) {
        k = 0;
        l = strlen(a);
        for (i = 0; i < l; i++) {
            if (a[i] == '4' || a[i] == '7') {
                k++;
            }
        }
        if (k == 4 || k == 7) {
            printf("YES\n");
        } else
            printf("NO\n");
    }
    return 0;
}
