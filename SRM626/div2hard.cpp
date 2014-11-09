#include <bits/stdc++.h>
using namespace std;
struct NegativeGraphDiv2 {
	long long findMin(int N, vector <int> s, vector <int> t, vector <int> weight, int charges) {
		int E = weight.size();
		for (int& x : s) -- x;
		for (int& x : t) -- x;
		vector<vector<long long>> dist(N, vector<long long>(N, 1<<30));
		for (int i = 0; i < N; ++ i) dist[i][i] = 0;
		for (int i = 0; i < E; ++ i) {
			dist[s[i]][t[i]] = min(dist[s[i]][t[i]], (long long)weight[i]);
		}
		for (int k = 0; k < N; ++ k) for (int i = 0; i < N; ++ i) for (int j = 0; j < N; ++ j) {
			dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
		vector<vector<long long>> xdist(charges + 1, vector<long long>(N));
		for (int i = 0; i < N; ++ i) xdist[0][i] = dist[i][N-1];
		for (int k = 1; k <= charges; ++ k) {
			xdist[k] = xdist[k-1];
			for (int i = 0; i < N; ++ i) for (int j = 0; j < E; ++ j) {
				xdist[k][i] = min(xdist[k][i], dist[i][s[j]] - weight[j] + xdist[k-1][t[j]]);
			}
		}
		return xdist[charges][0];
	}
};
