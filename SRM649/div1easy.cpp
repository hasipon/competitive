#include <bits/stdc++.h>
using namespace std;
bool visited[51][51][51][2];
bool memo[51][51][51][2];
struct Decipherability {
	int N;
	string s;
	bool f(int p, int q, int t, bool u) {
		if (t == 0) return u;
		if (visited[p][q][t][u]) return memo[p][q][t][u];
		visited[p][q][t][u] = true;
		for (int i = p; i < N; ++ i) {
			for (int j = q; j < N; ++ j) if (s[i] == s[j]) {
				if (f(i+1, j+1, t-1, u || (i != j))) return memo[p][q][t][u] = true;
			}
		}
		return memo[p][q][t][u] = false;
	}
	bool func(string s_, int K) {
		s = s_;
		N = s.length();
		return !f(0, 0, N - K, false);
	}
	string check(string s, int K) {
		return func(s, K) ? "Certain" : "Uncertain";
	}
};
