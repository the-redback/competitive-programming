#include <bits/stdc++.h>
using namespace std;

#define D(x) cerr << #x << " = " << x << '\n'
#define DD(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << '\n'
#define DDD(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << '\n'

#define mem(x, y) memset(x, y, sizeof(x))
typedef long long LL;

const int MAX = 1000006;
int n, k, tot, kOne[MAX], kLen[MAX];
char str[MAX];
int TC, dp[MAX][3], visit[MAX][3];

void fuck(int idx) {
	for (int i = idx; i >= 1; i -= k) {
		kOne[i] = str[i]-'0';
		kLen[i] = 1;
		if (i != idx) {
			kOne[i] += kOne[i+k];
			kLen[i] += kLen[i+k];
		}
	}
}

void preProcess() {
	tot = 0;
	for (int i = 1; i <= n; i++) {
		tot += str[i]-'0';
		kOne[i] = kLen[i] = 0;
	}
	for (int i = 1, j = n; i <= k; i++, j--) {
		fuck(j);
	}
}

int DP(int idx, bool mustClear) {
	if (idx > n) {
		return 0;
	}

	if (visit[idx][mustClear] == TC) {
		return dp[idx][mustClear];
	}

	int ret = INT_MAX;
	if (mustClear) {
		ret = kOne[idx];
	} else {
		int add = 0;
		if (str[idx] == '0') {
			add = 1;
		}
		ret = min(ret, add+DP(idx+k, false));
		ret = min(ret, add+DP(idx+k, true));
	}

	visit[idx][mustClear] = TC;
	return dp[idx][mustClear] = ret;
}

int solve() {
	int ret = tot, leftOne = 0;
	for (int i = 1; i <= n; i++) {
		int cur = leftOne; // zero
		int rightOne = tot - kOne[i];
		cur += rightOne; // zero
		int rightK = min(DP(i, false), DP(i, true));
		cur += rightK; // one
		ret = min(ret, cur);

		if (str[i] == '1') {
			leftOne++;
			tot--;
		}
	}
	return ret;
}

int main() {
	int test;

	cin >> test;
	while (test--) {
		TC++;
		scanf("%d %d", &n, &k);
		scanf("%s", str+1);
		preProcess();
		printf("%d\n", solve());
	}

    return 0;
}
