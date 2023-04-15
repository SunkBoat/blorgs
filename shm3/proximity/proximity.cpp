#include "bits/stdc++.h"
using namespace std;

struct g {
	int t, num;
}a[1919810];

int mx = -1, n, k;

bool cmp(g x, g y) {
	if (x.num == y.num) return x.t < y.t;
	return x.num < y.num; 
}

int main() {
	freopen ("proximity.in", "r", stdin);
	freopen ("proximity.out", "w", stdout);
	scanf ("%d%d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		scanf ("%d", &a[i].num);
		a[i].t = i;
	}
	sort(a + 1, a + n + 1, cmp);
	for (int i = 1; i <= n; ++i) {
		if (a[i].num == a[i - 1].num && (a[i].t - a[i - 1].t <= k)) mx = max(mx, a[i].num);
	}
	cout << mx;
	return 0;
}
