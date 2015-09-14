#include <bits/stdc++.h>
using namespace std;
int n, X, P, Q;
int a[20], b[20];
const int mod = 1000000007;
long long f(int x, int p, int q) {
	if (p == 0) {
		if (x > 0) return 0;
		for (int i = 1; i <= P; ++ i) cout << i << "*" << b[i] << " "; cout << "q*" << q << endl;
		return 1;
	}
	long long r = 0;
	for (b[p] = a[p]; q - (b[p] - a[p]) >= 0 && x - b[p] * p >= 0; ++ b[p]) {
		r = (r + f(x - b[p] * p, p - 1, q - (b[p] - a[p]))) % mod;
	}
	return r;
}
int main() {
	cin >> n >> X >> P;
	Q = 0;
	for (int i = 0; i < n; ++ i) {
		string s;
		cin >> s;
		if (s == "?") ++ Q;
		else ++a[atoi(s.c_str())];
	}
	if (a[0]) {
		cout << 0 << endl;
	} else {
		cout << f(X, P, Q) << endl;
	}
}
