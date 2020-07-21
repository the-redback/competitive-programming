#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

// vector
vector<int> nodes;
vector<vector<int>> edge;
vector<int> who;

int vector_ninja() {
    int n, m;
    cin >> n >> m;

    nodes.resize(n);
    edge.resize(m);
}

// Graph directions : 12 o'clock - clockwise
// ll dx[]={-1,0,1,0};
// ll dy[]={0,1,0,-1};
// ll dx[]={-1,-1,0,1,1,1,0,-1};
// ll dy[]={0,1,1,1,0,-1,-1,-1};
