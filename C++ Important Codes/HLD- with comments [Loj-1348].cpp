/**
Problem Description:
you are given a tree (a connected graph with no cycles) with n nodes,
nodes represent places, edges represent roads. In each node,
initially there are an arbitrary number of genies.
But the numbers of genies change in time.
So, you are given a tree, the number of genies in each node and several queries of two types. They are:

1)      0 i j, it means that you have to find the total number of genies in the nodes that occur in path from node i to j (0 <= i, j < n).
2)      1 i v, it means that number of genies in node i is changed to v (0 <= i < n, 0 <= v <= 1000).
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
#define NN        50010

#define read(a)   scanf("%lld",&a)


#define root 0
#define LN 16

vector <ll> adj[NN];
ll baseArray[NN], ptr, value[NN];
ll chainNo, chainInd[NN], chainHead[NN], posInBase[NN];
ll depth[NN], par[NN][LN], subsize[NN];
ll seg[NN * 4];

/*
 * make_tree:
 * Used to construct the segment tree. It uses the baseArray for construction
 */
void make_tree(ll node, ll low, ll high) {
    if (low == high) {
        seg[node] = baseArray[low];
        return;
    }
    ll left = node << 1;
    ll right = left | 1;
    ll mid = (low + high) >> 1;

    make_tree(left, low, mid);
    make_tree(right, mid + 1, high);
    seg[node] = seg[left] + seg[right];
    return;
}

/*
 * update_tree:
 * Point update. Update a single element of the segment tree.
 */
void update_tree(ll node, ll low, ll high, ll ind, ll val) {

    if (low == ind && low == high) {
        seg[node] = val;
        return;
    }
    ll left = node << 1;
    ll right = left | 1;
    ll mid = (low + high) >> 1;

    if (ind <= mid)
        update_tree(left, low, mid, ind, val);
    else
        update_tree(right, mid + 1, high, ind, val);

    seg[node] = seg[left] + seg[right];
    return ;
}

/*
 * query_tree:
 * Given S and E, it will return the maximum value in the range [S,E)
 */
ll query_tree(ll node, ll low, ll high, ll rlow, ll rhigh) {

    if (low >= rlow && high <= rhigh) {
        return seg[node];
    }
    ll left = node << 1;
    ll right = left | 1;
    ll mid = (low + high) >> 1;


    if (rhigh <= mid)
        return query_tree(left, low, mid, rlow, rhigh);
    else if (rlow > mid)
        return query_tree(right, mid + 1, high, rlow, rhigh);
    else {
        ll L = query_tree(left, low, mid, rlow, mid);
        ll R = query_tree(right, mid + 1, high, mid + 1, rhigh);
        return L + R;
    }
}

/*
 * query_up:
 * It takes two nodes u and v, condition is that v is an ancestor of u
 * We query the chain in which u is present till chain head, then move to next chain up
 * We do that way till u and v are in the same chain, we query for that part of chain and break
 */

ll query_up(ll u, ll v) {
    ll uchain, vchain = chainInd[v], ans = 0;
    // uchain and vchain are chain numbers of u and v
    while (1) {
        uchain = chainInd[u];
        if (uchain == vchain) {
            // Both u and v are in the same chain, so we need to query from u to v, update answer and break.
            // We break because we came from u up till v, we are done
            //if(u==v) break;
            ans += query_tree(1, 1, ptr - 1, posInBase[v], posInBase[u]);
            // Above is call to segment tree query function
            break;
        }
        ans += query_tree(1, 1, ptr - 1, posInBase[chainHead[uchain]], posInBase[u]);
        // Above is call to segment tree query function. We do from chainHead of u till u. That is the whole chain from
        // start till head. We then update the answer
        u = chainHead[uchain]; // move u to u's chainHead
        u = par[u][0]; //Then move to its parent, that means we changed chains
    }
    return ans;
}

/*
 * LCA:
 * Takes two nodes u, v and returns Lowest Common Ancestor of u, v
 */
ll LCA(ll u, ll v) {


    if (depth[u] < depth[v])
        swap(u, v);
    ll diff = depth[u] - depth[v];
    for (ll i = 0; i < LN; i++)
        if ( (diff >> i) & 1 )
            u = par[u][i];
    if (u == v)
        return u;
    for (ll i = LN - 1; i >= 0; i--)
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    return par[u][0];
}

ll query(ll u, ll v) {
    /*
     * We have a query from u to v, we break it into two queries, u to LCA(u,v) and LCA(u,v) to v
     */
    ll lca = LCA(u, v);
    ll ans = query_up(u, lca); // One part of path
    ll ans2 = query_up(v, lca); // another part of path
    return ans + ans2 - query_up(lca, lca); // take the maximum of both paths
}

/*
 * change:
 * We just need to find its position in segment tree and update it
 */
void change(ll u, ll val) {
    //ll u = otherEnd[i];
    update_tree(1, 1, ptr - 1, posInBase[u], val);
}

/*
 * Actual HL-Decomposition part
 * Initially all entries of chainHead[] are set to -1.
 * So when ever a new chain is started, chain head is correctly assigned.
 * As we add a new node to chain, we will note its position in the baseArray.
 * In the first for loop we find the child node which has maximum sub-tree size.
 * The following if condition is failed for leaf nodes.
 * When the if condition passes, we expand the chain to special child.
 * In the second for loop we recursively call the function on all normal nodes.
 * chainNo++ ensures that we are creating a new chain for each normal child.
 */
void HLD(ll curNode, ll prev) {
    if (chainHead[chainNo] == -1) {
        chainHead[chainNo] = curNode; // Assign chain head
    }
    chainInd[curNode] = chainNo;
    posInBase[curNode] = ptr; // Position of this node in baseArray which we will use in Segtree
    baseArray[ptr++] = value[curNode];

    ll sc = -1, ncost;
    // Loop to find special child
    for (ll i = 0; i < adj[curNode].size(); i++)
        if (adj[curNode][i] != prev) {
            if (sc == -1 || subsize[sc] < subsize[adj[curNode][i]]) {
                sc = adj[curNode][i];
            }
        }

    if (sc != -1) {
        // Expand the chain
        HLD(sc, curNode);
    }

    for (ll i = 0; i < adj[curNode].size(); i++)
        if (adj[curNode][i] != prev) {
            if (sc != adj[curNode][i]) {
                // New chains at each normal node
                chainNo++;
                HLD(adj[curNode][i], curNode);
            }
        }
}

/*
 * dfs used to set parent of a node, depth of a node, subtree size of a node
 */

void dfs(ll cur, ll prev, ll _depth = 0) {
    par[cur][0] = prev;
    depth[cur] = _depth;
    subsize[cur] = 1;
    for (ll i = 0; i < adj[cur].size(); i++)
        if (adj[cur][i] != prev) {
            dfs(adj[cur][i], cur, _depth + 1);
            subsize[cur] += subsize[adj[cur][i]];
        }
}

int main() {
#ifdef redback
    freopen("C:\\Users\\Maruf\\Desktop\\in.txt", "r", stdin);
#endif
    ll tc, t = 1;
    scanf("%lld ", &tc);
    while (tc--) {
        ptr = 1;
        ll n;
        scanf("%lld", &n);
        // Cleaning step, new test case
        for (ll i = 0; i <= n; i++) {
            adj[i].clear();
            chainHead[i] = -1;
            for (ll j = 0; j < LN; j++) par[i][j] = -1;
        }

        for (ll i = 0; i < n; i++) {
            read(value[i]);
        }

        for (ll i = 1; i < n; i++) {
            ll u, v, c;
            scanf("%lld %lld", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        chainNo = 0;
        dfs(root, -1); // We set up subsize, depth and parent for each node
        HLD(root, -1); // We decomposed the tree and created baseArray
        make_tree(1, 1, ptr - 1); // We use baseArray and construct the needed segment tree

        // Below Dynamic programming code is for LCA.
        for (ll lev = 1; lev <= LN - 1; lev++) {
            for (ll i = 0; i < n; i++) {
                if (par[i][lev - 1] != -1)
                    par[i][lev] = par[par[i][lev - 1]][lev - 1];
            }
        }

        ll q;
        scanf("%lld", &q);
        printf("Case %lld:\n", t++);

        while (q--) {
            ll tp;
            scanf("%lld", &tp);

            ll a, b;

            scanf("%lld %lld", &a, &b);
            if (tp == 0) {
                ll ans = query(a, b);
                printf("%lld\n", ans);
            } else {
                change(a, b);
            }
        }
    }
    return 0;
}

/*

Sample Input
1

4
10 20 30 40
0 1
1 2
1 3
3
0 2 3
1 1 100
0 2 3


Output for Sample Input
Case 1:
90
170




*/
