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

typedef long long ll;
typedef unsigned long long llu;

/*

Dictionary contains N words.
Search if a string exists in Dictionary or Not.

2 Operation:
Insert: It inserts words in dictionary.
Search: It serches for words in dictionary.

*/

struct trie {
    bool endmark;
    int next[26];
    trie() {
        endmark = 0;
        for (ll i = 0; i < 26; i++) next[i] = -1;
    }
};

vector<trie> tree;

void Insert(string arr, int start) {  /// Insert arr string
    ll node = 0;
    for (ll i = start; i < arr.size(); i++) {
        ll id = arr[i] - 'a';

        if (tree[node].next[id] == -1) {
            tree[node].next[id] = (int)tree.size();
            tree.push_back(trie());
        }
        node = tree[node].next[id];
    }
    tree[node].endmark = 1;  /// endmark marks the ending of a string
}

bool Search(string arr) {  /// Search arr string
    int node = 0;
    for (int i = 0; i < arr.size(); i++) {
        int id = arr[i] - 'a';
        if (tree[node].next[id] == -1) return false;
        node = tree[node].next[id];
    }
    return tree[node].endmark;
}

int main() {
    // ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef redback
    // freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
#endif

    char arr[100];

    ll t = 1, tc;
    scanf("%lld", &tc);  /// Test case
    ll i, j, k, l, m, n;
    while (tc--) {
        tree.push_back(trie());  /// Root node actually.

        scanf("%lld", &n);  /// No of word in dictionary.
        ll flag = 1;
        for (i = 0; i < n; i++) {
            scanf("%s", &arr);
            Insert(arr, 0);  /// Insert arr string into dictionary.
        }

        scanf("%lld", &m);  /// No of queries.
        for (i = 0; i < m; i++) {
            scanf("%s", &arr);
            if (Search(arr))
                puts("Yes");
            else
                puts("No");
        }

        tree.clear();  /// Delete The Memory.
    }
    return 0;
}

/*
Input:
1

3
aaa
asdasd
sssssss

6
aaa
aa
aaaa
asdasd
sssssss
ssasd

Output:
Yes
No
No
Yes
Yes
No
*/
