#include <bits/stdc++.h>
using namespace std;
struct BoardFoldingDiv2 {
	vector<bool> g(const vector<vector<bool>>& a) {
		vector<bool> r(a.size());
		r[0] = true;
		for (int i = 0; i < a.size(); ++ i) if (r[i]) {
			for (int j = 1; 2*j <= a.size() - i; ++ j) {
				for (int k = 0; k < j; ++ k) {
					if (a[i+k] != a[i+2*j-1-k]) goto next;
				}
				r[i + j] = true;
				next:;
			}
		}
		return r;
	}
	int f(vector<vector<bool>> a) {
		vector<bool> a1 = g(a);
		reverse(a.begin(), a.end());
		vector<bool> a2 = g(a);
		int r = 0;
		for (int i = 0; i < a.size(); ++ i) for (int j = 0; i + j < a.size(); ++ j) {
			if (a1[i] && a2[j]) ++ r;
		}
		return r;
	}
	int howMany(vector <string> paper) {
		int N = paper.size();
		int M = paper[0].size();
		vector<vector<bool>> a(N, vector<bool>(M));
		vector<vector<bool>> b(M, vector<bool>(N));
		for (int i = 0; i < N; ++ i) for (int j = 0; j < M; ++ j) {
			a[i][j] = b[j][i] = (paper[i][j] == '1');
		}
		return f(a) * f(b);
	}
};
