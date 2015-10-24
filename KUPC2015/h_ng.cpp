#include <bits/stdc++.h>
using namespace std;
long hoge(long n) {
	for (long x = 1; ; ++ x) {
		if (__builtin_popcount(x) == __builtin_popcount(x+n)) return x;
	}
}
long N;
map<pair<int,int>, bool> memo;
bool g(int p, int q) {
	if (memo.count({p,q})) return memo[{p,q}];
	bool res = false;
	return memo[{p,q}] = res;
}
long f(long n) {
	N = n;
	long r = 0;
	memo.clear();
	int c = 1;
	for (int i = 60; i >= 0; -- i) {
		if (c == 0) {
			if ((n>>i)&1) {
				c = 1;
			} else {
				c = 0;
			}
		} else if (c == 1) {
			if ((n>>i)&1) {
				if (g(i-1, 1)) {
					c = 2;
				} else {
					r |= 1L << i;
					c = 0;
				}
			} else {
				c = 0;
			}
		} else {
			if ((n>>i)&1) {
				if (g(i-1, 1)) {
					c = 2;
				} else {
					r |= 1L << i;
					c = 2;
				}
			} else {
				r |= 1L << i;
				c = 2;
			}
		}
	}
	return r;
}
int main() {
	for (int i = 1; i <= 1000; ++ i) {
		cout << i << " " << f(i) << " " << hoge(i) << endl;
	}
}
