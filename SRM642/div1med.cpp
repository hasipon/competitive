#include <bits/stdc++.h>
using namespace std;

const int INF = 1<<29;

struct edge { int to, cap, cost, rev; };
int V;
vector<edge> G[500];
int dist[500];
int prevv[500], preve[500];

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

struct TaroCutting {
	int getNumber(vector <int> height, vector <int> add, vector <int> device, int t) {
		int n = height.size();
		V = 3 + n + t + device.size();
		add_edge(0, 2, n, 0);
		for (int i = 0; i < n; ++ i) {
			add_edge(1, 3 + i, 1, 0);
			add_edge(3 + i, 0, 1, height[i] + add[i] * t);
			for (int j = 0; j < t; ++ j) {
				add_edge(3 + i, 3 + n + j, 1, add[i] * (t-j-1));
			}
		}
		for (int k = 0; k < device.size(); ++ k) {
			for (int j = 0; j < t; ++ j) {
				add_edge(3 + n + j, 3 + n + t + k, 1, device[k]);
			}
			add_edge(3 + n + t + k, 2, n, 0);
		}
		return min_cost_flow(1, 2, n);
	}
};
