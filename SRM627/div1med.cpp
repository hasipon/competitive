#include <bits/stdc++.h>
using namespace std;
int K;
vector<int> V;
vector<vector<int>> G;
bool visited[1001];
int ans;
vector<int> bit;
int sum(int i) {
	int s = 0;
	while (i > 0) {
		s += bit[i];
		i -= i & -i;
	}
	return s;
}
void add (int i, int x) {
	while (i <= 1001) {
		bit[i] += x;
		i += i & -i;
	}
}
struct GraphInversions {
	void f(int pos, int v, int prev, int s) {
		if (visited[v]) return;
		int ss = s + pos - sum(V[v]);
		add(V[v], 1);
		if (pos == K-1) {
			ans = min(ans, ss);
			add(V[v], -1);
			return;
		}
		visited[v] = true;
		for (int x : G[v]) if (x != prev) f(pos+1, x, v, ss);
		visited[v] = false;
		add(V[v], -1);
	}
	int getMinimumInversions(vector <int> A, vector <int> B, vector <int> V_, int K_) {
		K = K_;
		V = V_;
		G = vector<vector<int>>(A.size());
		for (int i = 0; i < A.size(); ++ i) {
			G[A[i]].push_back(B[i]);
			G[B[i]].push_back(A[i]);
		}
		bit = vector<int>(1010);
		ans = 1<<30;
		for (int i = 0; i < A.size(); ++ i) {
			f(0, i, -1, 0);
		}
		if (ans == (1<<30)) return -1;
		return ans;
	}
};
