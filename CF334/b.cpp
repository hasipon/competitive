#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int main() {
	int p, k;
	cin >> p >> k;
	long long r = 1;
	if (k == 0) {
		for (int i = 1; i < p; ++ i) r = r * p % mod;
	} else if (k == 1) {
		for (int i = 0; i < p; ++ i) r = r * p % mod;
	} else {
		long long x = k;
		int c = 1;
		while (x != 1) {
			x = x * k % p;
			++ c;
		}
		int d = (p - 1) / c;
		for (int i = 0; i < d; ++ i) r = r * p % mod;
	}
	cout << r << endl;
}
