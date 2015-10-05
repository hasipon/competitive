#include <bits/stdc++.h>
using namespace std;
struct TheKingsRoadsDiv2 {
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
	bool solve(int h, vector <int> a, vector <int> b) {
		set<pair<int,int>> e;
		for (int i = 0; i < a.size(); ++ i) {
			int x = a[i]-1;
			int y = b[i]-1;
			if (x > y) swap(x, y);
			if (x != y) e.insert({x, y});
		}
		if (e.size() == a.size()-1) {
			vector<vector<int>> g(a.size());
			for (auto p : e) {
				g[p.first].push_back(p.second);
				g[p.second].push_back(p.first);
			}
			return check(h, g);
		} else if (e.size() == a.size()) {
			for (auto q : e) {
				vector<vector<int>> g(a.size());
				for (auto p : e) if (p != q) {
					g[p.first].push_back(p.second);
					g[p.second].push_back(p.first);
				}
				if (check(h, g)) return true;
			}
		}
		return false;
	}
	string getAnswer(int h, vector <int> a, vector <int> b) {
		return solve(h, a, b) ? "Correct" : "Incorrect";
	}
};
