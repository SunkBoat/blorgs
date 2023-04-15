#include "bits/stdc++.h"
using namespace std;
vector<int> win[2333];
//win[i]:第i只牛战胜了的牛 
vector<int> lose[2333];
//lose[i]:第i只牛战败了的牛 

int n, m, cnt;

int find_win(int a, int b) {
	for (int i = 0; i < win[a].size(); ++i)
		if (win[a][i] == b) return 1;
	return 0;
}

int find_lose(int a, int b) {
	for (int i = 0; i < lose[a].size(); ++i) {
		if (lose[a][i] == b) return 1;
	}
	return 0;
}

void win_pushdown(int a, int b) {
	if (!find_win(a, b)) win[a].push_back(b);
	for (int i = 0; i < win[b].size(); ++i) {
		win_pushdown(a, win[b][i]); 
	}
}

void lose_pushdown(int a, int b) {
	if (!find_lose(a, b)) lose[a].push_back(b);
	for (int i = 0; i < lose[b].size(); ++i) {
		lose_pushdown(a, lose[b][i]);
	} 
}

void win_pushup(int a, int b) {
	if (!find_win(a, b)) win[a].push_back(b);
	for (int i = 0; i < lose[a].size(); ++i) {
		win_pushup(lose[a][i], b);
	}
}

void lose_pushup(int a, int b) {
	if (!find_lose(a, b)) lose[a].push_back(b);
	for (int i = 0; i < win[a].size(); ++i) {
		lose_pushup(win[a][i], b);
	}
}

int main() {
	
	freopen ("contest.in", "r", stdin);
	freopen ("contest.out", "w", stdout);
	
	scanf ("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int u, v;
		scanf ("%d%d", &u, &v);
		win_pushdown(u, v);
		lose_pushdown(v, u);
		win_pushup(u, v);
		lose_pushup(v, u);
	}
	for (int i = 1; i <= n; ++i) {
		int s = win[i].size() + lose[i].size();
		if (s == (n - 1)) ++cnt;
	}
	cout << cnt;
}
