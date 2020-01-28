/**
 *    @author     : Maruf Tuhin
 *    @School     : CUET CSE 11
 *    @Topcoder   : the_redback
 *    @CodeForces : the_redback
 *    @UVA        : the_redback
 *    @link       : http://www.fb.com/maruf.2hin
 */
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<set>
#include<sstream>
#include<stack>
using namespace std;

#define mp make_pair
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define mem(a,b) memset(a,b,sizeof(a))
#define inf 1e9
#define eps 1e-9
#define NN 50050


int color[NN];
vector<int>arr;              //topological sorted node
vector<int>Graph[NN];        //Graph Before SCC
vector<int>transGraph[NN];   //Transpose Graph Before SCC
vector<int>newGraph[NN];     //New Graph After SCC
vector<pair<int, int> >v;    //Edges Before SCC
int id[NN];                  //Id of Nodes After SCC
int amount[NN];              //Amount of original node
// in a SCC node


int dfs_1st(int u) {
    color[u] = true;
    for (int i = 0; i < Graph[u].size(); i++) {
        if (!color[Graph[u][i]])
            dfs_1st(Graph[u][i]);
    }
    arr.pb(u);
}

int dfs_2nd(int u, int k) {
    color[u] = true;
    id[u] = k;

    for (int i = 0; i < transGraph[u].size(); i++) {
        if (!color[transGraph[u][i]])
            dfs_2nd(transGraph[u][i], k);
    }
}

int scc(int n) {
    arr.clear();
    mem(color, 0);
    int i, j, k, l;

    for (i = 1; i <= n; i++) //Topological Sort
        if (color[i] == 0)
            dfs_1st(i);

    reverse(all(arr));

    mem(id, -1);
    mem(color, 0);
    k = 0;

    for (i = 0; i < arr.size(); i++) { //Identify SCC
        if (!color[arr[i]]) {
            dfs_2nd(arr[i], k + 1);
            amount[id[arr[i]]] = 1; //Amount of actual node
            //in SCC node
            k++;
        } else
            amount[id[arr[i]]]++;
    }

    int node = k;    //Number of SCC node

    for (i = 0; i < v.size(); i++) { //Build SCC graph
        k = v[i].first;
        l = v[i].second;

        if (id[k] != id[l])
            newGraph[id[k]].pb(id[l]);
    }

    return node;  //Number of SCC node.
}


main() {
    ios_base::sync_with_stdio(false);
    int t = 1, tc;
    int i, j, k, l, m, n, man;

    cin >> tc;  //Test Case
    while (tc--) {
        cin >> n >> m; //n=node, m=edge

        for (i = 0; i <= n; i++) {
            Graph[i].clear();
            transGraph[i].clear();
            newGraph[i].clear();
        }
        v.clear();

        for (i = 0; i < m; i++) {
            cin >> k >> l;
            Graph[k].pb(l);
            transGraph[l].pb(k);
            v.pb(make_pair(k, l));
        }

        int sum = scc(n);
        printf("Case %d: %d\n", t++, sum);
    }
    return 0;
}

/*
=======[ input ]=======
2

4 4
1 2
2 1
3 4
4 3

3 3
1 2
2 3
3 1

=======[ output ]=======
Case 1: 2
Case 2: 1
*/
