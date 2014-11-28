#include <bits/stdc++.h>
using namespace std;

long long f(long long n) {
	long long r = (long long)(sqrt((double)n) + 0.5);
	for (long long i = r + 100; i >= r - 100; -- i) {
		if (i * i == n) return i;
	}
	return -1;
}
	long long findMinimumValue(long long x, long long y) {
		long long nt = f(x + y);
		if (nt < 0) return -1;
		if (x == 0) return 0;
		long long s = 0, t = 0;
		for (long long i = 0; i < nt; ++ i) {
			s += 2 * i + 1;
			t += 2 * (nt-i) - 1;
			if (x % 2 == s % 2) {
				if (s <= x && x <= t) return i + 1;
			}
		}
		return -1;
	}
int main() {
	for (int i = 1; i <= 15; ++ i) {
		vector<int> a(i*i+1, 1<<30);
		for (int p = 0; p < (1<<i); ++ p) {
			int s = 0;
			for (int j = 0; j < i; ++ j) if ((p>>j)&1) s += 2*j+1;
			a[s] = min(a[s], __builtin_popcount(p));
		}
		for (int j = 0; j <= i*i; ++ j) if (a[j] == 1<<30) a[j] = -1;
		for (int j = 0; j <= i*i; ++ j) {
			long long r = findMinimumValue(j, i*i-j);
			if (r != a[j]) {
				cout << i << " " << j << " " << a[j] << " " << r << endl;
			}
		}
	}
}
