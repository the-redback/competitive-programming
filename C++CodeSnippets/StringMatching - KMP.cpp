/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> buildFailure(string& pattern) {
    int m = pattern.size();
    vector<int> fail(m, 0);

    int q = 0;
    for (int i = 1; i < m; i++) {
        // q is always fail[i - 1].
        while (q > 0 && pattern[i] != pattern[q]) {
            q = fail[q - 1];
        }
        if (pattern[i] == pattern[q]) {
            q++;
        }
        fail[i] = q;
    }
    return fail;
}

int KMP(string& str, string& pattern) {
    int n = str.size();
    int m = pattern.size();

    vector<int> fail = buildFailure(pattern);

    int q = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        while (q > 0 && str[i] != pattern[q]) {
            q = fail[q - 1];
        }
        if (str[i] == pattern[q]) {
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
