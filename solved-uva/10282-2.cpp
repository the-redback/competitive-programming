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
#define inf       HUGE_VAL
#define mem(a, b) memset(a, b, sizeof(a))

int main() {
    map<string, string> mp;
    char s[100010], ss[100010];
    char a[100010];
    int tc, t = 1, i, j, k, l;
    while (gets(a)) {
        l = strlen(a);
        if (l == 0) break;
        i = 0, k = 0;
        for (i = 0; i < l; i++) {
            if (a[i] == ' ') break;
            s[k++] = a[i];
        }
        s[k] = 0;
        k = 0;
        i++;
        for (; i < l; i++) {
            ss[k++] = a[i];
        }
        ss[k] = 0;
        mp[ss] = s;
    }
    while (gets(s)) {
        if (mp.find(s) == mp.end())
            printf("eh\n");
        else
            printf("%s\n", mp[s].c_str());
    }
    return 0;
}
