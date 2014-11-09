#include <bits/stdc++.h>
using namespace std;
struct NegativeGraphDiv1 {
	vector<vector<long long>> f(vector<vector<long long>> A, vector<vector<long long>> B) {
		int N = A.size();
		vector<vector<long long>> C(N, vector<long long>(N, 1<<30));
		for (int i = 0; i < N; ++ i) for (int j = 0; j < N; ++ j) for (int k = 0; k < N; ++ k) {
			C[i][j] = min(C[i][j], A[i][k] + B[k][j]);
		}
		return C;
	}
	long long findMin(int N, vector <int> s, vector <int> t, vector <int> weight, int charges) {
		int E = weight.size();
		for (int& x : s) -- x;
		for (int& x : t) -- x;
		vector<vector<long long>> dist(2*N, vector<long long>(2*N, 1<<30));
		for (int i = 0; i < E; ++ i) {
			dist[s[i]][t[i]] = min(dist[s[i]][t[i]], (long long)weight[i]);
			dist[s[i]+N][t[i]+N] = min(dist[s[i]+N][t[i]+N], (long long)weight[i]);
			dist[s[i]+N][t[i]] = min(dist[s[i]+N][t[i]], (long long)-weight[i]);
		}
		for (int k = 0; k < 2*N; ++ k) for (int i = 0; i < 2*N; ++ i) for (int j = 0; j < 2*N; ++ j) {
			dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		}
		if (charges == 0) return dist[0][N-1];
		vector<vector<long long>> A(N, vector<long long>(N));
		for (int i = 0; i < N; ++ i) for (int j = 0; j < N; ++ j) A[i][j] = dist[i+N][j];
		for (int i = 0; i < N; ++ i) A[i][i] = min(A[i][i], 0LL);
		vector<vector<long long>> D(N, vector<long long>(N, 1<<30));
		for (int i = 0; i < N; ++ i) D[i][i] = 0;
		for (int k = charges; k > 0; k /= 2) {
			if (k % 2) D = f(D, A);
			A = f(A, A);
		}
		return D[0][N-1];
	}
};
