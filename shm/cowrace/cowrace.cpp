#include "bits/stdc++.h"
#define ll long long
using namespace std;

ll dis_a[1919810];
ll dis_b[1919810];
int T;

ll s;
int t;
int cnt;
int W;
//当前情况
//A 超过 B 则为 1
//B 超过 A 则为 -1 

int n, m;

int main() {
	freopen ("cowrace.in", "r", stdin);
	freopen ("cowrace.out", "w", stdout);
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		scanf ("%lld%d", &s, &t);
		for (int j = 1; j <= t; ++j) {
			++T;
			dis_a[T] = dis_a[T - 1] + s;
		}
	}
	T = 0;
	for (int i = 1; i <= m; ++i) {
		scanf ("%lld%d", &s, &t);
		for (int j = 1; j <= t; ++j) {
			++T;
			dis_b[T] = dis_b[T - 1] + s;
		}
	}
//	for(int i=1;i<=T;++i)cout<<dis_a[i]<<' ';cout<<endl;
//	for(int i=1;i<=T;++i)cout<<dis_b[i]<<' ';cout<<endl;
	for (int i = 1; i <= T; ++i) {
		if (W == 0 && dis_a[i] > dis_b[i]) W = 1;
		else if (W == 0 && dis_a[i] < dis_b[i]) W = -1;
		else if (dis_a[i] > dis_b[i] && W == -1) {
			W = 1;
			++cnt;
//			cout << i << ' ' << cnt << ':' << dis_a[i] << ' ' << dis_b[i] << endl;
		} else if (dis_a[i] < dis_b[i] && W == 1) {
			W = -1;
			++cnt;
//			cout << i << ' ' << cnt << ':' << dis_a[i] << ' ' << dis_b[i] << endl;
		}
	}
	cout << cnt;
} 
