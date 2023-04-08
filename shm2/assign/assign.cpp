#include "bits/stdc++.h"
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;

vector<int> d[25];

int sx[1919810], sy[1919810];

int f[1919810];

int n, k, m, tot;

void dfs(int dep) {
	if (dep > n) {
		for (int i = 1; i <= m; ++i)
			if (f[sx[i]] != f[sy[i]]) return;
//		for(int i=1;i<=n;++i)cout<<f[i]<<' ';cout<<endl;
		++tot;
		return;
	}
	int t[4];
	for (int i = 1; i <= 3; ++i) t[i] = 0;
	for (int i = 0; i < d[dep].size(); ++i) t[f[d[dep][i]]] = 1;
	for (int i = 1; i <= 3; ++i)
		if (t[i] == 0) {
			f[dep] = i;
			dfs(dep + 1);
		}
}

int main() {
	freopen ("assign.in", "r", stdin);
	freopen ("assign.out", "w", stdout);
	
	cin >> n >> k;
	for (int i = 1; i <= k; ++i) {
		char op;
		int x, y;
		cin >> op >> x >> y;
		if (op == 'S') {
			sx[++m] = x; sy[m] = y;
		} else {
			d[x].push_back(y); d[y].push_back(x);
		}
	}
	dfs(1);
	printf ("%d", tot);
}
