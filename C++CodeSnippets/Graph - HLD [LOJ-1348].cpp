/**
 *                                   ____
 *       ____ ___  ____ ________  __/ __/
 *      / __ `__ \/ __ `/ ___/ / / / /_
 *     / / / / / / /_/ / /  / /_/ / __/
 *    /_/ /_/ /_/\__,_/_/   \__,_/_/
 *
 *    @link : https://the-redback.com
 */

#include <cstdio>
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long llu;

#define NN 10010

vector<ll> adj[NN];
ll baseArray[NN], ptr, value[NN];
ll chainNo, chainInd[NN], chainHead[NN], posInBase[NN];
ll depth[NN], par[NN][16], subsize[NN];
ll seg[NN * 4];

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
    return;
}

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

ll query_up(ll u, ll v) {  // v is an ancestor of u
    ll uchain, vchain = chainInd[v], ans = 0;
    // uchain and vchain are chain numbers of u and v
    while (1) {
        uchain = chainInd[u];
        if (uchain == vchain) {
            ans += query_tree(1, 1, ptr - 1, posInBase[v], posInBase[u]);
            break;
        }
        ans += query_tree(1, 1, ptr - 1, posInBase[chainHead[uchain]],
                          posInBase[u]);
        u = chainHead[uchain];  // move u to u's chainHead
        u = par[u][0];  // Then move to its parent, that means we changed
                        // chains
    }
    return ans;
}

ll LCA(ll u, ll v) {
    if (depth[u] < depth[v]) swap(u, v);
    ll diff = depth[u] - depth[v];
    for (ll i = 0; i < 16; i++)
        if ((diff >> i) & 1) u = par[u][i];
    if (u == v) return u;
    for (ll i = 16 - 1; i >= 0; i--)
        if (par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    return par[u][0];
}

ll query(ll u, ll v) {
    ll lca = LCA(u, v);
    ll ans = query_up(u, lca);               // One part of path
    ll ans2 = query_up(v, lca);              // another part of path
    return ans + ans2 - query_up(lca, lca);  // take the maximum of both paths
}

void change(ll u, ll val) { update_tree(1, 1, ptr - 1, posInBase[u], val); }

void HLD(ll curNode, ll prev) {
    if (chainHead[chainNo] == -1) {
        chainHead[chainNo] = curNode;  // Assign chain head
    }
    chainInd[curNode] = chainNo;
    posInBase[curNode] = ptr;  // Position of this node in baseArray which we
                               // will use in Segtree
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
    cin >> tc;
    while (tc--) {
        ptr = 1;
        ll n;
        cin >> n;
        // Cleaning step, new test case
        for (ll i = 0; i <= n; i++) {
            adj[i].clear();
            chainHead[i] = -1;
            for (ll j = 0; j < 16; j++) par[i][j] = -1;
        }

        for (ll i = 0; i < n; i++) {
            cin >> value[i];
        }

        for (ll i = 1; i < n; i++) {
            ll u, v, c;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        chainNo = 0;
        dfs(0, -1);  // We set up subsize, depth and parent for each node
        HLD(0, -1);  // We decomposed the tree and created baseArray
        make_tree(
            1, 1,
            ptr - 1);  // We use baseArray and construct the needed segment tree

        // Below Dynamic programming code is for LCA.
        for (ll lev = 1; lev <= 16 - 1; lev++) {
            for (ll i = 0; i < n; i++) {
                if (par[i][lev - 1] != -1)
                    par[i][lev] = par[par[i][lev - 1]][lev - 1];
            }
        }

        ll q;
        cin >> q;
        cout << "Case " << t++ << ":" << "\n";

        while (q--) {
            ll tp;
            cin >> tp;

            ll a, b;

            cin >> a >> b;
            if (tp == 0) {
                ll ans = query(a, b);
                cout << ans << "\n";
            } else {
                change(a, b);
            }
        }
    }
    return 0;
}
