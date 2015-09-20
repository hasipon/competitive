#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<int> C;
vector<vector<int>> g;
vector<int> parent;
void dfs(int p, int q) {
	for (
}
int main() {
	cin >> N >> M;
	if (N > 7) throw 1;
	C.resize(N);
	int sum = 0;
	for (auto& x : C) { cin >> x; sum += x; }
	if (sum > 7) throw 1;
	g.resize(N);
	for (int i = 0; i < M; ++ i) {
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	parent.resize(N, -1);
	dfs(0);
}
