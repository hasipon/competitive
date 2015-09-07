#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<pair<int,bool>>> var;
vector<int> ans;
vector<bool> sat;
vector<vector<pair<pair<int,bool>,int>>> g;
vector<bool> used;
vector<int> color, vertices, cycle;
bool found;
int firstVertex;
void dfs(int v) {
	used[v] = true;
	for (auto x : g[v]) {
		int to = x.first.first;
		if (!used[to]) {
			ans[x.second] = x.first.second;
			dfs(to);
		}
	}
}
bool findCycle(int v, int lastEdge) {
	color[v] = 1;
	vertices.push_back(v);
	for (auto x : g[v]) {
		if (x.second == lastEdge) {
			continue;
		}
		int to = x.first.first;
		if (color[to] == 1) {
			ans[x.second] = x.first.second;
			firstVertex = to;
			found = true;
			return true;
		}
		if (color[to] == 0) {
			if (findCycle(to, x.second)) {
				ans[x.second] = x.first.second;
				cycle.push_back(v);
				used[v] = true;
				if (v == firstVertex) {
					return false;
				} else {
					return true;
				}
			}
			if (found) {
				return false;
			}
		}
	}
	color[v] = 2;
	vertices.pop_back();
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	var.resize(m);
	for (int i = 0; i < n; ++ i) {
		int k;
		cin >> k;
		for (int j = 0; j < k; ++ j) {
			int vij;
			cin >> vij;
			if (vij > 0) {
				var[vij-1].push_back({i, true});
			} else {
				var[-vij-1].push_back({i, false});
			}
		}
	}
	ans.resize(m);
	sat.resize(n);
	g.resize(n);
	for (int i = 0; i < m; ++ i) {
		if (var[i].size() == 1) {
			if (var[i][0].second) ans[i] = 1;
			sat[var[i][0].first] = true;
		} else if (var[i].size() == 2) {
			if (var[i][0].second == var[i][1].second) {
				if (var[i][0].second) ans[i] = 1;
				sat[var[i][0].first] = sat[var[i][1].first] = true;
			} else {
				g[var[i][0].first].push_back({var[i][1], i});
				g[var[i][1].first].push_back({var[i][0], i});
			}
		}
	}
	used.resize(n);
	for (int i = 0; i < n; ++ i) if (!used[i] && sat[i]) {
		dfs(i);
	}
	color.resize(n);
	for (int i = 0; i < n; ++i) if (!used[i]) {
		vertices.clear();
		found = false;
		cycle.clear();
		findCycle(i, -1);
		if (!found) {
			cout << "NO\n";
			return 0;
		}
		for (int v : cycle) {
			dfs(v);
		}
	}
	cout << "YES" << endl;
	for (int x : ans) cout << x;
	cout << endl;
}
