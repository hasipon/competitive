#include <bits/stdc++.h>
using namespace std;
int main() {
	int N, L;
	cin >> N >> L;
	vector<int> a(N), b(N), c(N);
	for (int i = 0; i < N; ++ i) cin >> a[i] >> b[i] >> c[i];
	vector<int> bb, cc;
	for (int i = 0; i < N; ++ i) {
		for (int j = 0; j < b[i]; ++ j) {
			bb.push_back(a[i]);
			if (bb.size() > 5000) throw 1;
		}
		for (int j = 0; j < c[i]; ++ j) {
			cc.push_back(a[i]);
			if (cc.size() > 5000) throw 1;
		}
	}
	long long res = 1LL<<60;
	for (int i = 0; i < bb.size(); ++ i) {
		long long r = 0;
		for (int j = 0; j < bb.size(); ++ j) {
			int d = abs(bb[j] - cc[(i+j)%cc.size()]);
			r += min(d, L - d);
		}
		res = min(res, r);
	}
	cout << res << endl;
}
