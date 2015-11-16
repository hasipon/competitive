#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> l, m, w;
int a[30];
int s, t, u;
unordered_map<long long, int> q[2];
unordered_map<long long, vector<int>> o[2];
long long g(unsigned x, unsigned y) {
	long long r = x;
	r <<= 32;
	r |= y;
	return r;
}
void f(int p, int x, int y, int z) {
	if (p == t) {
		long long k = g(y-x, z-x);
		if (!q[u].count(k) || x+y+z > q[u][k]) {
			q[u][k] = x+y+z;
			o[u][k] = vector<int>(&a[s], &a[t]);
		}
		return;
	}
	{
		a[p] = 0;
		f(p+1, x+l[p], y+m[p], z);
	}
	{
		a[p] = 1;
		f(p+1, x+l[p], y, z+w[p]);
	}
	{
		a[p] = 2;
		f(p+1, x, y+m[p], z+w[p]);
	}
}
int main() {
	int n;
	cin >> n;
	l.resize(n);
	m.resize(n);
	w.resize(n);
	for (int i = 0; i < n; ++ i) cin >> l[i] >> m[i] >> w[i];
	s = 0; t = n/2; u = 0;
	f(s, 0, 0, 0);
	s = n/2; t = n; u = 1;
	f(s, 0, 0, 0);
	int r = -1;
	long long kk;
	for (auto x : q[0]) {
		long long k = g(y-x, z-x);
		pair<int,int> k { -x.first.first, -x.first.second };
		auto it = q[1].find(k);
		if (it != q[1].end()) {
			int rr = x.second + it->second;
			if (rr > r) {
				r = rr;
				kk = x.first;
			}
		}
	}
	if (r < 0) {
		cout << "Impossible" << endl;
	} else {
		string S[3] = {"LM", "LW", "MW"};
		for (auto& x : o[0][kk]) {
			cout << S[x] << endl;
		}
		for (auto& x : o[1][make_pair(-kk.first, -kk.second)]) {
			cout << S[x] << endl;
		}
	}
}
