#include "bits/stdc++.h"
#pragma GCC optimize(3, "Ofast", "inline")

using namespace std;

struct Node {
	int x1, y1, x2, y2;
}a[1919810];

bool cmp(Node x, Node y) {
	return ((x.x2 - x.x1 + 1) * (x.y2 - x.y1 + 1)) > ((y.x2 - y.x1 + 1) * (y.y2 - y.y1 + 1));
}

int f[1919810];//±»°üº¬ 

int main() {
	
	freopen ("painting.in", "r", stdin);
	freopen ("painting.out", "w", stdout);
	
	int n, ans;
	scanf ("%d", &n);
	ans = n;
	for (int i = 1; i <= n; ++i) scanf ("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			if (f[j] == 1) continue;
			if ((a[j].x1 < a[i].x1) && (a[j].x2 > a[i].x2)) {
				--ans;
				f[i] = 1;
				break;
			}
		}
	}
	printf ("%d", ans);
}
