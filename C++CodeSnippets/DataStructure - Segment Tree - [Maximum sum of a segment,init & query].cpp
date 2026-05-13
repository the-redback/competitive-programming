#include <algorithm>
#include <iostream>
using namespace std;

#define inf 1e9
#define NN 10010

struct Data {
    int totalsum, maxsum, leftmax, rightmax;
    Data(int k) { totalsum = maxsum = leftmax = rightmax = k; }
    Data() {
        totalsum = 0;
        maxsum = leftmax = rightmax = -inf;
    }
};

Data tree[NN];
int a[65010];

Data merge(Data a, Data b) {
    Data ret;
    ret.totalsum = (a.totalsum + b.totalsum);
    ret.maxsum = max(max(a.maxsum, b.maxsum), a.rightmax + b.leftmax);
    ret.leftmax = max(a.leftmax, a.totalsum + b.leftmax);
    ret.rightmax = max(b.rightmax, b.totalsum + a.rightmax);
    return ret;
}

void init(int node, int low, int high) {
    if (low == high) {
        tree[node] = Data(a[low]);
        return;
    }

    int left = node * 2;
    int right = left + 1;
    int mid = (low + high) / 2;

    init(left, low, mid);
    init(right, mid + 1, high);
    tree[node] = merge(tree[left], tree[right]);
    return;
}

Data query(int node, int low, int high, int qlow, int qhigh) {
    // No Overlap
    if (qhigh < low || qlow > high) return Data();

    // Complete overlap
    if (qlow <= low && high <= qhigh) return tree[node];

    int left = node * 2;
    int right = left + 1;
    int mid = (low + high) / 2;

    Data L = query(left, low, mid, qlow, qhigh);
    Data R = query(right, mid + 1, high, qlow, qhigh);
    return merge(L, R);
}

int main() {
    ios_base::sync_with_stdio(false);
    int i, k;
    int n, x, y;
    // cin>>tc;
    while (cin >> n) {
        for (i = 1; i <= n; i++) cin >> a[i];
        init(1, 1, n);
        cin >> k;
        while (k--) {
            cin >> x >> y;
            Data l = query(1, 1, n, x, y);
            cout << l.maxsum << "\n";
        }
    }
    return 0;
}

/*
problem: https://www.spoj.com/problems/GSS1/
Input:
3
-1 2 3
1
1 2
Output:
2
*/
