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
using namespace std;

vector<int> buildFailure(string& p) {
    int m = p.size();

    vector<int> fail(m, 0);

    int q = 0;

    for (int i = 1; i < m; i++) {
        while (q > 0 && p[i] != p[q]) {
            q = fail[q - 1];
        }

        if (p[i] == p[q]) {
            q++;
        }

        fail[i] = q;
    }

    return fail;
}

int KMP(string& s, string& p) {
    int n = s.size();
    int m = p.size();

    vector<int> fail = buildFailure(p);

    int q = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        while (q > 0 && s[i] != p[q]) {
            q = fail[q - 1];
        }

        if (s[i] == p[q]) {
            q++;
        }

        if (q == m) {
            cnt++;
            q = fail[q - 1];
        }
    }

    return cnt;
}

int main() {
    string s = "abababa";
    string p = "aba";

    cout << KMP(s, p) << '\n';

    return 0;
}
