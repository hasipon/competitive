#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL<<60;
int N;
vector<vector<pair<int,int>>> G;
vector<long> dist, bound;
struct MaliciousPath {
	void dijk() {
		dist = vector<long>(N, INF);
		priority_queue<pair<long, int>> Q;
		dist[N-1] = 0;
		Q.push({0L, N-1});
		while (!Q.empty()) {
			long d = -Q.top().first;
			int v = Q.top().second;
			Q.pop();
			if (dist[v] == d) for (auto x : G[v]) {
				int u = x.first, w = x.second;
				long dd = max(dist[v] + w, bound[u]);
				if (dd < dist[u]) {
					dist[u] = dd;
					Q.push({-dd, u});
				}
			}
		}
	}
	long long minPath(int N_, int K, vector <int> from, vector <int> to, vector <int> cost) {
		N = N_;
		G.resize(N);
		for (int i = 0; i < from.size(); ++ i) {
			G[to[i]].push_back({from[i], cost[i]});
		}
		bound.resize(N);
		for (int i = 0; i <= K; ++ i) {
			dijk();
			for (int v = 0; v < N; ++ v) {
				for (auto x : G[v]) {
					int u = x.first, w = x.second;
					bound[u] = max(bound[u], dist[v] + w);
				}
			}
		}
		return dist[0] >= INF ? -1 : dist[0];
	}
};
