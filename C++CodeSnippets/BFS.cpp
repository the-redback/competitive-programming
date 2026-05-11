#include <bits/stdc++.h>
using namespace std;

#define NN 10010

int dis[NN];
int parent[NN];
int color[NN];
vector<int> g[NN];

void BFS(int s, int v) {
    int len, x, k;
    queue<int> Q;
    parent[s] = -1;
    dis[s] = 0;
    color[s] = 1;

    Q.push(s);
    while (!Q.empty()) {
        x = Q.front();
        Q.pop();
        len = g[x].size();
        for (int i = 0; i < len; i++)
            if (g[x][i] && color[g[x][i]] == 0) {
                k = g[x][i];
                color[k] = 1;
                dis[k] = dis[x] + 1;
                parent[k] = x;
                Q.push(k);
            }
        color[x] = 2;
        printf("%d ", x);
    }

    printf("\n***distances***\n");
    for (int i = 1; i <= v; i++) printf("distance[%d]= %d\n", i, dis[i]);
    return;
}

int main() {
    int v, e, s, d;
    printf("Enter no of vertices: ");
    scanf("%d", &v);
    printf("Enter no of edges: ");
    scanf("%d", &e);
    for (int i = 1; i <= e; i++) {
        printf("Enter source and destination: ");
        scanf("%d %d", &s, &d);
        g[s].push_back(d);
        g[d].push_back(s);
    }
    printf("Enter source of graph: ");
    scanf("%d", &s);
    BFS(s, v);
    return 0;
}