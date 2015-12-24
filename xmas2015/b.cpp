#include <bits/stdc++.h>
using namespace std;
int N, M;
vector<set<int>> G;
vector<pair<int,int>> ans;

struct UnionFind {
	vector<int> data;
	UnionFind(int n) : data(n, -1) {}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	bool merge(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) return false;
		if (data[y] < data[x]) swap(x, y);
		data[x] += data[y];
		data[y] = x;
		return true;
	}
};

bool solve() {
	if (N == 1) return true;
	for (int i = 0; i < N; ++ i) if (G[i].size() == N-1) return false;
	int p = 0;
	for (int i = 0; i < N; ++ i) {
		if (G[i].empty()) {
			for (int j = 0; j < N; ++ j) if (i != j) {
				ans.push_back({i, j});
			}
			return true;
		}
		if (G[i].size() < G[p].size()) p = i;
	}
	UnionFind uf(N);
	for (int i = 0; i < N; ++ i) if (i != p) {
		if (!G[p].count(i)) {
			ans.push_back({p, i});
			uf.merge(p, i);
		}
	}
	for (int i : G[p]) {
		for (int j = 0; j < N; ++ j) if (i != j && !G[i].count(j) && uf.root(i) != uf.root(j)) {
			ans.push_back({i, j});
			uf.merge(i, j);
		}
	}
	return ans.size() == N-1;
}
int main() {
	cin >> N >> M;
	G.resize(N);
	for (int i = 0; i < M; ++ i) {
		int p, q;
		cin >> p >> q;
		-- p; -- q;
		G[p].insert(q);
		G[q].insert(p);
	}
	if (solve()) {
		cout << "Yes" << endl;
		for (auto e : ans) {
			cout << e.first+1 << " " << e.second+1 << endl;
		}
	} else {
		cout << "No" << endl;
	}
}
