#include <bits/stdc++.h>
using namespace std;
const int INF = 1<<30;
const int mod = 1000000009;
struct DrivingPlans {
	int N;
	vector<vector<pair<int,int>>> G;
	vector<int> a0, a1, memo;
	vector<int> f(int s) {
		vector<int> r(N, INF);
		priority_queue<pair<int,int>> Q;
		r[s] = 0;
		Q.push(make_pair(0, s));
		while (!Q.empty()) {
			int d = -Q.top().first;
			int p = Q.top().second;
			Q.pop();
			for (auto x : G[p]) {
				int dd = d + x.second;
				if (dd < r[x.first]) {
					r[x.first] = dd;
					Q.push(make_pair(-dd, x.first));
				}
			}
		}
		return r;
	}
	int g(int p) {
		if (p == N-1) return 1;
		if (memo[p] >= 0) return memo[p];
		int r = 0;
		for (auto x : G[p]) {
			if (a0[p] + x.second == a0[x.first] && a0[x.first] + a1[x.first] == a0[N-1]) {
				r += g(x.first);
				r %= mod;
			}
		}
		return memo[p] = r;
	}
	int count(int N_, vector <int> A, vector <int> B, vector <int> C) {
		N = N_;
		G = vector<vector<pair<int,int>>>(N);
		vector<bool> Z(N);
		for (int i = 0; i < A.size(); ++ i) {
			int x = A[i]-1;
			int y = B[i]-1;
			G[x].push_back(make_pair(y, C[i]));
			G[y].push_back(make_pair(x, C[i]));
			if (C[i] == 0) Z[x] = Z[y] = true;
		}
		a0 = f(0);
		a1 = f(N-1);
		for (int i = 0; i < N; ++ i) {
			if (a0[i] + a1[i] == a0[N-1] && Z[i]) return -1;
		}
		memo = vector<int>(N, -1);
		return g(0);
	}
};
