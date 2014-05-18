#include <bits/stdc++.h>
using namespace std;

const int INF = 1<<29;

struct edge { int to, cap, cost, rev; };
int V;
vector<edge> G[120];
int dist[120];
int prevv[120], preve[120];

void add_edge(int from, int to, int cap, int cost) {
	G[from].push_back((edge){to, cap, cost, (int)G[to].size()});
	G[to].push_back((edge){from, 0, -cost, (int)G[from].size()-1});
}

int min_cost_flow(int s, int t, int f) {
	int res = 0;
	while (f > 0) {
		fill(dist, dist + V, INF);
		dist[s] = 0;
		bool update = true;
		while (update) {
			update = false;
			for (int v = 0; v < V; ++ v) {
				if (dist[v] == INF) continue;
				for (int i = 0; i < G[v].size(); ++ i) {
					edge& e = G[v][i];
					if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {
						dist[e.to] = dist[v] + e.cost;
						prevv[e.to] = v;
						preve[e.to] = i;
						update = true;
					}
				}
			}
		}
		if (dist[t] == INF) return -1;
		int d = f;
		for (int v = t; v != s; v = prevv[v]) {
			d = min(d, G[prevv[v]][preve[v]].cap);
		}
		f -= d;
		res += d * dist[t];
		for (int v = t; v != s; v = prevv[v]) {
			edge& e = G[prevv[v]][preve[v]];
			e.cap -= d;
			G[v][e.rev].cap += d;
		}
	}
	return res;
}

struct SpecialCells {
	int guess(vector <int> x, vector <int> y) {
		set<pair<int,int>> s;
		map<int,int> xs, ys;
		for (int i = 0; i < x.size(); ++ i) {
			s.insert(make_pair(x[i], y[i]));
			++ xs[x[i]];
			++ ys[y[i]];
		}
		V = xs.size() + ys.size() + 2;
		vector<int> z;
		for (auto i = xs.begin(); i != xs.end(); ++ i) {
			add_edge(V-2, z.size(), i->second, 0);
			z.push_back(i->first);
		}
		for (auto i = ys.begin(); i != ys.end(); ++ i) {
			add_edge(z.size(), V-1, i->second, 0);
			z.push_back(i->first);
		}
		for (int i = 0; i < xs.size(); ++ i) {
			for (int j = xs.size(); j < V-2; ++ j) {
				add_edge(i, j, 1, s.count(make_pair(z[i], z[j])));
			}
		}
		return min_cost_flow(V-2, V-1, x.size());
	}
};
