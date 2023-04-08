#include "bits/stdc++.h"
using namespace std;

char ch[50005];

string g;
string f[335771];
int m;

int mx = -0x3f3f3f3f;
string qwq;

int Solv(string x, string y) {
	int L = 0, O = 0, V = 0, E = 0;
	for (int i = 0; i < x.size(); ++i) {
		if (x[i] == 'L') ++L;
		if (x[i] == 'O') ++O;
		if (x[i] == 'V') ++V;
		if (x[i] == 'E') ++E;
	}
	for (int i = 0; i < y.size(); ++i) {
		if (y[i] == 'L') ++L;
		if (y[i] == 'O') ++O;
		if (y[i] == 'V') ++V;
		if (y[i] == 'E') ++E;
	}
	return ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;
}

int main() {
	
	freopen ("calc.in", "r", stdin);
	freopen ("calc.out", "w", stdout);
	
	gets(ch);
	for (int i = 0; ch[i] != '\0'; ++i) {
		g += ch[i];
	}
	gets(ch);
	for (int i = 0, j = 0; ch[i] != '\0'; ++i) {
		if (ch[i] == '\"' && j == 0) j = 1, m = m + 1;
		else if (ch[i] == '\"' && j == 1) j = 0;
		else if (j == 1) {
			f[m] += ch[i];
		}
	}
	sort(f + 1, f + m + 1);
	for (int i = 1; i <= m; ++i) {
		int delt = Solv(g, f[i]);
		if (delt > mx) {
			mx = delt;
			qwq = f[i];
		}
	}
	cout << qwq;
}
