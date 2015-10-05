#include <bits/stdc++.h>
using namespace std;
struct TheKingsRoadsDiv1 {
	vector<vector<int>> g;
	bool dfs(int h, const vector<vector<int>>& g, int pos, int parent) {
		if (h == 1) return g[pos].size() == 1;
		if (parent != -1 && g[pos].size() != 3) return false;
		for (int x : g[pos]) if (x != parent) {
			if (!dfs(h-1, g, x, pos)) return false;
		}
		return true;
	}
	bool check(int h, const vector<vector<int>>& g) {
		int root = -1;
		for (int i = 0; i < g.size(); ++ i) {
			if (g[i].size() == 2) {
				if (root != -1) return false;
				root = i;
			}
		}
		if (root == -1) return false;
		return dfs(h, g, root, -1);
	}
	bool backtrack(int bad, int h, const vector<pair<int,int>>& e2, int pos, vector<int>& selected) {
		if (bad == 0) {
			for (int p : selected) {
				int x = e2[p].first;
				int y = e2[p].second;
				g[x].erase(find(g[x].begin(), g[x].end(), y));
				g[y].erase(find(g[y].begin(), g[y].end(), x));
			}
			if (check(h, g)) return true;
			for (int p : selected) {
				int x = e2[p].first;
				int y = e2[p].second;
				g[x].push_back(y);
				g[y].push_back(x);
			}
			return false;
		}
		for (int i = pos; i < e2.size(); ++ i) {
			selected.push_back(i);
			if (backtrack(bad-1, h, e2, i+1, selected)) return true;
			selected.pop_back();
		}
		return false;
	}
	bool solve(int h, vector <int> a, vector <int> b) {
		set<pair<int,int>> e;
		for (int i = 0; i < a.size(); ++ i) {
			int x = a[i]-1;
			int y = b[i]-1;
			if (x > y) swap(x, y);
			if (x != y) e.insert({x, y});
		}
		int bad = 3 - ((int)a.size() - (int)e.size());
		if (bad < 0) return false;
		g.resize(a.size()-2);
		for (auto p : e) {
			g[p.first].push_back(p.second);
			g[p.second].push_back(p.first);
		}
		if (bad == 0) check(h, g);
		map<int,int> c;
		vector<bool> d(g.size());
		for (int x = 0; x < g.size(); ++ x) if (g[x].size() == 1) {
			int y = g[x][0];
			++ c[y];
			d[x] = true;
		}
		for (;;) {
			vector<int> v;
			for (auto x : c) if (x.second == 2) v.push_back(x.first);
			if (v.empty()) break;
			c.clear();
			for (int x : v) if (g[x].size() == 3) {
				int y = -1;
				for (int z : g[x]) if (!d[z]) {
					y = z;
				}
				if (y == -1) continue;
				++ c[y];
				d[x] = true;
			}
		}
		vector<pair<int,int>> e2;
		for (auto p : e) {
			if (!d[p.first] && !d[p.second]) e2.push_back(p);
		}
		if (e2.size() >= 70) return false;
		vector<int> selected;
		return backtrack(bad, h, e2, 0, selected);
	}
	string getAnswer(int h, vector <int> a, vector <int> b) {
		return solve(h, a, b) ? "Correct" : "Incorrect";
	}
};
