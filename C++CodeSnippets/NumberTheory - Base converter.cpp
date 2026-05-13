#include <cctype>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

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
    string temp = to_string(sum);
    strcpy(b, temp.c_str());
}

int main() {
    char a[100], b[100];
    int i, j, k, l, m, n;
    cout << "CURRENT base: ";
    cin >> n;
    cout << "\n" << "Number: ";
    cin >> a;
    cout << "\n" << "REQUIRED base: ";
    cin >> m;
    for (i = 0; a[i] != 0; i++) {
        a[i] = toupper(a[i]);
        if (a[i] >= 'A')
            k = a[i] - 'A' + 10;
        else
            k = a[i] - '0';
        if (k >= n) {
            cout << "\n" << "** Oops!!! Sorry...... " << a << " is not of " << n << " base." << "\n" << "\n";
            return 0;
        }
    }
    if (n == 10) {
        dec2other(a, b, m);
        cout << "\n" << "Number in " << m << " base: " << b << "\n" << "\n";
    } else if (m == 0) {
        other2dec(a, b, n);
        cout << "\n" << "Number in " << m << " base: " << b << "\n" << "\n";
    } else {
        other2dec(a, b, n);
        dec2other(b, a, m);
        cout << "\n" << "Number in " << m << " base: " << a << "\n" << "\n";
    }
    return 0;
}
