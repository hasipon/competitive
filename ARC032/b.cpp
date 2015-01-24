#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<vector<int>> G;
vector<bool> visited;
void f(int x) {
	if (visited[x]) return;
	visited[x] = true;
	for (int y : G[x]) f(y);
}
int main() {
	cin >> N >> M;
	G.resize(N);
	visited.resize(N);
	for (int i = 0; i < M; ++ i) {
		int a, b;
		cin >> a >> b;
		-- a; -- b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int r = 0;
	for (int i = 0; i < N; ++ i) if (!visited[i]) {
		++ r;
		f(i);
	}
	cout << r - 1 << endl;
}
