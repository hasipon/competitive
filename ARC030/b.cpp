#include <bits/stdc++.h>
using namespace std;
int n, x;
vector<int> h;
vector<vector<int>> G;
pair<int, bool> f(int p, int q) {
	int r = 0;
	for (int x : G[p]) if (x != q) {
		auto rr = f(x, p);
		if (rr.second) r += rr.first + 1;
	}
	return make_pair(r, h[p] || r != 0);
}
int main() {
	cin >> n >> x;
	-- x;
	h.resize(n);
	for (int i = 0; i < n; ++ i) cin >> h[i];
	G.resize(n);
	for (int i = 0; i < n-1; ++ i) {
		int a, b;
		cin >> a >> b;
		-- a; -- b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	cout << f(x, -1).first * 2 << endl;
}
