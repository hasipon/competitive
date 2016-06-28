#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> w;
vector<vector<bool>> a;
map<int, int> memo;
int g(int p) {
	if (p == n) return 0;
	if (memo.count(p)) return memo[p];
	int r = g(p+1);
	for (int i = 2; p+i <= n; i += 2) {
		if (a[p][p+i-1]) r = max(r, g(p+i) + i);
	}
	return memo[p] = r;
}
int f() {
	a = vector<vector<bool>>(n, vector<bool>(n));
	for (int i = 0; i+1 < n; ++ i) {
		if (abs(w[i]-w[i+1]) <= 1) a[i][i+1] = true;
	}
	for (int i = 4; i <= n; ++ i) {
		for (int j = 0; j+i <= n; ++ j) {
			if (a[j+1][j+i-2] && abs(w[j]-w[j+i-1]) <= 1) a[j][j+i-1] = true;
			for (int k = j+2; k < j+i; k += 2) if (a[j][k-1] && a[k][j+i-1]) a[j][j+i-1] = true;
		}
	}
	memo.clear();
	return g(0);
}
int main() {
	for (;;) {
		cin >> n;
		if (!n) break;
		w = vector<int>(n);
		for (int i = 0; i < n; ++ i) cin >> w[i];
		cout << f() << endl;
	}
}
