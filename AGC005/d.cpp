#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> a;
long long g(long long n) {
	if (n < 0) return 0;
	return (n+1) * (n+2) / 2;
}
long long f(int x, int y, int z) {
	return g(z-x) - g(y-x) - g(z-y-1);
	/*
	long long r = 0;
	for (int i = x; i < z; ++ i) {
		for (int j = i+1; j <= z; ++ j) {
			if (i <= y && y < j) ++ r;
		}
	}
	return r;
	*/
}
int main() {
	cin >> N;
	a.resize(N);
	for (int i = 0; i < N; ++ i) {
		int x;
		cin >> x;
		a[x-1] = i;
	}
	set<int> s;
	s.insert(0);
	s.insert(N);
	long long r = 0;
	for (int i = 0; i < N; ++ i) {
		int x = a[i];
		auto it = s.upper_bound(x);
		auto jt = it;
		-- it;
		s.insert(x);
		s.insert(x+1);
		r += f(*it, x, *jt) * (i+1);
	}
	cout << r << endl;
}
