#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& x : a) cin >> x;
	vector<vector<int> > gg(n+1);
	for (int i = 1; i <= n; ++ i) {
		gg[__gcd(i,n)].push_back(i);
	}
	long long res = 0;
	for (int g = 1; g < n; ++ g) if (n % g == 0) {
		vector<bool> u(2*n);
		for (int i = 0; i < g; ++ i) {
			int mx = -1;
			for (int j = i; j < n; j += g) mx = max(mx, a[j]);
			for (int j = i; j < n; j += g) u[j] = u[j+n] = (a[j] == mx);
		}
		int s = -1;
		for (int i = 0; i < n; ++ i) {
			if (!u[i] && u[i+1]) { s = i; break; }
		}
		if (s < 0) {
			res += (long long)n * gg[g].size();
		} else {
			map<int,int> cnt;
			for (int x, y = s; y < n + s; ++ y) {
				if (!u[y] && u[y+1]) x = y;
				if (u[y] && !u[y+1]) {
					++ cnt[y-x];
				}
			}
			for (auto p : cnt) {
				for (auto i : gg[g]) {
					long long z = p.first - i + 1;
					if (z > 0) res += z * p.second;
				}
			}
		}
	}
	cout << res << endl;
}
