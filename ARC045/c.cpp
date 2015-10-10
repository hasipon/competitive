#include <bits/stdc++.h>
using namespace std;
int N, X;
vector<vector<pair<int,int>>> g;
map<int,int> cnt;
void f(int p, int q, int r) {
	++ cnt[r];
	for (auto x : g[p]) if (x.first != q) {
		f(x.first, p, r ^ x.second);
	}
}
int main() {
	cin >> N >> X;
	g.resize(N);
	for (int i = 1; i < N; ++ i) {
		int x, y, c;
		cin >> x >> y >> c;
		-- x; -- y;
		g[x].push_back({y,c});
		g[y].push_back({x,c});
	}
	f(0, -1, 0);
	long r = 0;
	for (auto x : cnt) {
		if (x.first == (x.first^X)) {
			r += (long)x.second * (x.second-1) / 2;
		} else if (x.first < (x.first^X)) {
			if (cnt.count(x.first^X)) {
				r += (long)x.second * cnt[x.first^X];
			}
		}
	}
	cout << r << endl;
}
