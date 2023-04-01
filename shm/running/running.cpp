#include "bits/stdc++.h"
using namespace std;

vector<int> v[114514];
int n, e, m;
int vis[1919810];
int ans[1919810];
int f[1919810];

queue<int> q;

void bfs() {
	int t = 1, u;
	q.push(t);
	while (!q.empty()) {
		u = q.front();
		f[u] = 1;
		q.pop();
		for (int j = 0; j < v[u].size(); ++j) {
			int x = v[u][j];
			if (!vis[x]) {
				vis[x] = 1;
				q.push(x);
			}
		}
	}
}

int main() {
	freopen ("running.in", "r", stdin);
	freopen ("running.out", "w", stdout);
	scanf ("%d%d", &n, &e);
	for (int i = 1; i <= e; ++i) {
		int x, y;
		scanf ("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 2; i < n; ++i) {
		for (int j = 1; j <= n; ++j) vis[j] = f[j] = 0;
		vis[i] = 1;
		bfs();
		if (f[n] == 0) ans[++m] = i;
	}
	cout << m << endl;
	for (int i = 1; i <= m; ++i) cout << ans[i] << ' ';
}
