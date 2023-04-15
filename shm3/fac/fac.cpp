#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int T;

ll t[1919810];
ll f[1919810];
ll x[1919810];

void calc(int a, ll b) {
	for (int i = 2; i * i <= a && i <= 120; ++i) {
		while (a % i == 0) ++t[i], a /= i;
	}
	if (a != 1 && a <= 120) ++t[a];
	for (int i = 1; i <= 130; ++i) t[i] *= (1ll * b);
}

void Solv() {
	int n;
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int a; ll b;
		scanf ("%d%lld", &a, &b);
		calc(a, b);
		for (int j = 1; j <= 120; ++j) f[j] += t[j], t[j] = 0ll;
//		for(int j=1;j<=10;++j)cout<<f[j]<<' ';cout<<endl;
	}
	int fg = 1;
	for (int i = 1; i <= 110; ++i)
		if (f[i] != 0) {
			fg = 0;
			break;
		}
	if (fg == 1) {
		puts("0"); return;
	}
	for (int i = 0; ; ++i) {
		calc(i, 1ll);
		for (int j = 1; j <= 120; ++j) x[j] += t[j], t[j] = 0;
		int flg = 1;
		for (int j = 1; j <= 120; ++j) {
			if (x[j] < f[j]) {
				flg = 0; break;
			}
		}
		if (flg == 1) {
			printf ("%d\n", i);
			return;
		}
	}
}

int main() {
	freopen ("fac.in", "r", stdin);
	freopen ("fac.out", "w", stdout);
	scanf ("%d", &T);
	while (T--) Solv();
}
