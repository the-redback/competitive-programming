/**
 *    @author     : Maruf Tuhin
 *    @College    : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : http://www.fb.com/maruf.2hin
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long llu;

#define ft        first
#define sd        second
#define mp        make_pair
#define pb(x)     push_back(x)
#define all(x)    x.begin(),x.end()
#define allr(x)   x.rbegin(),x.rend()
#define mem(a,b)  memset(a,b,sizeof(a))
#define inf       1e9
#define eps       1e-9
#define mod       1000000007
#define NN        1000000

#define read(a)   scanf("%lld",&a)
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
        for (ll i = 0; i < 26; i++)
            next[i] = -1;
    }
};

vector<trie>tree;

void Insert(string arr, int start) { ///Insert arr string
    ll node = 0;
    for (ll i = start; i < arr.size(); i++) {
        ll id = arr[i] - 'a';

        if (tree[node].next[id] == -1) {
            tree[node].next[id] = (int)tree.size();
            tree.pb(trie());
        }
        node = tree[node].next[id];
    }
    tree[node].endmark = 1; ///endmark marks the ending of a string
}

bool Search(string arr) { ///Search arr string
    int node = 0;
    for (int i = 0; i < arr.size(); i++) {
        int id = arr[i] - 'a';
        if (tree[node].next[id] == -1)
            return false;
        node = tree[node].next[id];
    }
    return tree[node].endmark;
}

int main() {
    //ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef redback
    // freopen("C:\\Users\\Maruf\\Desktop\\in.txt","r",stdin);
#endif

    char arr[100];


    ll t = 1, tc;
    read(tc);       ///Test case
    ll i, j, k, l, m, n;
    while (tc--) {
        tree.pb(trie());  ///Root node actually.

        read(n);      ///No of word in dictionary.
        ll flag = 1;
        for (i = 0; i < n; i++) {
            scanf("%s", &arr);
            Insert(arr, 0);  ///Insert arr string into dictionary.
        }

        read(m);   ///No of queries.
        for (i = 0; i < m; i++) {
            scanf("%s", &arr);
            if (Search(arr))
                puts("Yes");
            else
                puts("No");
        }

        tree.clear(); ///Delete The Memory.
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

