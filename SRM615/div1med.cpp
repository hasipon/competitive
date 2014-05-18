#include <bits/stdc++.h>
using namespace std;
struct LongLongTripDiv1 {
	string isAble(int N, vector <int> A, vector <int> B, vector <int> D, long long T) {
		vector<vector<pair<int,int>>> G(N);
		for (int i = 0; i < A.size(); ++ i) {
			G[A[i]].push_back(make_pair(B[i], D[i]));
			G[B[i]].push_back(make_pair(A[i], D[i]));
		}
		if (G[0].size() == 0) return "Impossible";
		int d = G[0][0].second;
		for (int i = 1; i < G[0].size(); ++ i) d = min(d, G[0][i].second);
		vector<vector<long long>> dist(20000, vector<long long>(50, 1LL<<60));
		priority_queue<pair<long long, pair<int,int>>> Q;
		Q.push(make_pair(0LL, make_pair(0,0)));
		dist[0][0] = 0;
		while (!Q.empty()) {
			long long x = -Q.top().first;
			auto p = Q.top().second;
			Q.pop();
			if (dist[p.first][p.second] != x) continue;
			for (int i = 0; i < G[p.second].size(); ++ i) {
				int m = (p.first + G[p.second][i].second) % (2*d);
				long y = x + G[p.second][i].second;
				int v = G[p.second][i].first;
				if (y < dist[m][v]) {
					Q.push(make_pair(-y, make_pair(m, v)));
					dist[m][v] = y;
				}
			}
		}
		return (dist[T % (2*d)][N-1] <= T) ? "Possible" : "Impossible";
	}
};
