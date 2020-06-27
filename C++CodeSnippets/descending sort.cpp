#include <bits/stdc++.h>
using namespace std;

bool comp(int a, int b) {
    return a > b;
}

main() {
    int a[100];
    int i;
    for (i = 0; i < 5; i++) {
        scanf("%d", &a[i]);
    }
    std::sort(a, a + 5, comp);
    for (i = 0; i < 5; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}