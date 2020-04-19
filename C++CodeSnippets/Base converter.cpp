#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cctype>

void dec2other(char a[], char b[], int m) {
    int i = 0, k;
    long long sum = atoi(a);
    while (sum != 0) {
        k = (sum % m);
        if (k >= 10)
            b[i++] = k + 'A' - 10;
        else
            b[i++] = k + '0';
        sum = sum / m;
    }
    b[i] = 0;
    strrev(b);
}
void other2dec(char a[], char b[], int n) {
    long long sum = 0;
    int i, j = 0, k, l;
    l = strlen(a);
    j = 0;
    for (i = l - 1; i >= 0; i--) {
        if (a[i] >= 'A')
            k = a[i] - 'A' + 10;
        else
            k = a[i] - 48;
        sum += k * pow(n, j);
        j++;
    }
    sprintf(b, "%lld", sum);
}

int main() {
    char a[100], b[100];
    int i, j, k, l, m, n;
    printf("CURRENT base: ");
    scanf("%d", &n);
    printf("\nNumber: ");
    scanf("%s", &a);
    printf("\nREQUIRED base: ");
    scanf("%d", &m);
    for (i = 0; a[i] != 0; i++) {
        a[i] = toupper(a[i]);
        if (a[i] >= 'A')
            k = a[i] - 'A' + 10;
        else
            k = a[i] - '0';
        if (k >= n) {
            printf("\n** Oops!!! Sorry...... %s is not of %d base.\n\n", a, n);
            return 0;
        }
    }
    if (n == 10) {
        dec2other(a, b, m);
        printf("\nNumber in %d base: %s\n\n", m, b);
    } else if (m == 0) {
        other2dec(a, b, n);
        printf("\nNumber in %d base: %s\n\n", m, b);
    } else {
        other2dec(a, b, n);
        dec2other(b, a, m);
        printf("\nNumber in %d base: %s\n\n", m, a);
    }
    return 0;
}
