#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> G;
vector<int> P;
map<int, int> C;
pair<int,int> f(int v, int prev) {
	pair<int,int> r(1<<30, -1);
	for (auto x : G[v]) {
		if (x.first != prev && C.count(x.second)) {
			r = min(r, make_pair(C[x.second], x.second));
			r = min(r, f(x.first, v));
		}
	}
	return r;
}
int main() {
	int N;
	cin >> N;
	if (N > 1000) throw 1;
	G.resize(N);
	P.resize(N);
	for (int i = 0; i < N-1; ++ i) {
		int a, b, c;
		cin >> a >> b >> c;
		-- a; -- b;
		G[a].push_back(make_pair(b, i));
		G[b].push_back(make_pair(a, i));
		P[i] = a;
		C[i] = c;
	}
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++ i) {
		int t, j, d;
		cin >> t;
		if (t == 1) {
			cin >> j >> d;
			-- j;
			if (C.count(j)) {
				C[j] += d;
			}
		} else {
			cin >> j;
			-- j;
			if (C.count(j)) {
				auto x = f(P[j], -1);
				cout << x.second+1 << endl;
				C.erase(x.second);
			} else {
				cout << -1 << endl;
			}
		}
	}
}
