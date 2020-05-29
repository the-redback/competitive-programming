#include <bits/stdc++.h>
using namespace std;

#define mem(x, y) memset(x, y, sizeof(x));

vector<int> v;
vector<int> L;
vector<int> I;
stack<int> ans;

void prework(void) {
    I.clear();
    L.clear();
    int i, k;
    k = 2000000000;
    I.push_back(-1 * k);

    for (i = 0; i < v.size(); i++) L.push_back(1);
    return;
}

int LIS(void) {
    int i, low, mid, high;
    for (i = 0; i < v.size(); i++) {
        low = 0;
        high = I.size() - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (v[i] > I[mid])
                low = mid + 1;
            else
                high = mid - 1;
        }
        if (low == I.size())
            I.push_back(v[i]);
        else
            I[low] = v[i];
        L[i] = low;
    }
    return I.size() - 1;
}

void show(void) {
    int i, j, k, max;
    max = 0;
    for (i = 0; i < L.size(); i++) {
        if (max < L[i]) {
            max = L[i];
            j = i;
        }
    }
    ans.push(v[j]);
    for (i = j - 1; i >= 0; i--) {
        if (v[i] < v[j] && L[i] == L[j] - 1) {
            ans.push(v[i]);
            j = i;
        }
    }
    while (ans.size()) {
        printf("%d\n", ans.top());
        ans.pop();
    }
    return;
}

main() {
    char a[10];
    int i, j, k, l, m, n, t = 0, T;
    scanf("%d", &T);
    getchar();
    getchar();
    while (T--) {
        // input taking methode in uva 497
        t++;
        v.clear();
        while (gets(a) && strlen(a)) {
            sscanf(a, "%d", &n);
            v.push_back(n);
        }
        if (v.size()) {
            prework();
            if (t != 1) puts("");
            printf("Max hits: %d\n", LIS());
            show();
        }
    }
    return 0;
}
