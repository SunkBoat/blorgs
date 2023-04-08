#include "bits/stdc++.h"
using namespace std;

int f[1919810];
int t[1919810];

int a[1919810];
int b[1919810];
int n, mx;

int main() {
	
	freopen ("gene.in", "r", stdin);
	freopen ("gene.out", "w", stdout);
	
	scanf ("%d", &n);
	for (int i = 1; i <= n; ++i) scanf ("%d", &a[i]);
	for (int i = 1; i <= n; ++i) scanf ("%d", &b[i]);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (a[j] == b[i]) t[i] = j;
		}
	}
	for (int i = 1; i <= n; ++i) {
		f[i] = 1;
		for (int j = 1; j < i; ++j) {
			if (t[i] > t[j]) f[i] = max(f[i], f[j] + 1);
		}
	}
	for (int i = 1; i <= n; ++i) mx = max(mx, f[i]);
	cout << mx;
}
