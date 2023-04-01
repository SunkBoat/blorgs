#include "bits/stdc++.h"
using namespace std;

struct Node {
	int x, dis;
	bool operator < (const Node& p) const {
		return dis > p.dis;
	}
};

struct Edge {
	int to, nxt, dis;
}e[1919810];

int hd[1919810];
int dis[1919810];
int c[1919810];
int cnt;
int n, m, k;
void add_edge(int u, int v, int d) {
	++cnt;
	e[cnt].to = v;
	e[cnt].dis = d;
	e[cnt].nxt = hd[u];
	hd[u] = cnt;
}

priority_queue<Node> q;

void dijkstra(int s, int t) {
	Node al, be;
	al.x = s; al.dis = c[s];
	dis[s] = c[s];
	q.push(al);
	while (!q.empty()) {
		be = q.top();
		q.pop();
		int u, v, d;
		u = be.x;
		for (int i = hd[u]; i; i = e[i].nxt) {
			v = e[i].to;
			d = be.dis + e[i].dis + c[v];
			if (d < dis[v]) {
				dis[v] = d;
				al.dis = d;
				al.x = v;
				q.push(al);
			}
		}
	}
//	for(int i=1;i<=n;++i)cout<<dis[i]<<' ';
//	cout<<endl;
}

int main() {
	freopen ("toll.in", "r", stdin);
	freopen ("toll.out", "w", stdout);
	scanf ("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i) scanf ("%d", &c[i]);
	for (int i = 1; i <= m; ++i) {
		int u, v, d;
		scanf ("%d%d%d", &u, &v, &d);
		add_edge(u, v, d);
		add_edge(v, u, d);
	}
	for (int i = 1; i <= k; ++i) {
		for (int j = 1; j <= n; ++j) dis[j] = 0x3f3f3f3f;
		int s, t;
		scanf ("%d%d", &s, &t);
//		cout<<s<<' '<<t<<endl;
		dijkstra(s, t);
		printf ("%d\n", dis[t]);
	}
}
