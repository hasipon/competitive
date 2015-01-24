#include <bits/stdc++.h>
using namespace std;
double memo[101];
double f(int n) {
	map<vector<int>, double> a;
	a[vector<int>(3)] = 1;
	for (int i = 0; i < n; ++ i) {
		map<vector<int>, double> b;
		a.swap(b);
		for (const auto& x : b) {
			for (int i = 0; i < 3; ++ i) {
				auto c = x.first;
				++c[i];
				sort(c.begin(), c.end());
				a[c] += x.second / 3;
			}
		}
	}
	vector<double> d(n+1);
	for (const auto& x : a) {
		if (x.first[1] == 0) {
			d[n] += x.second;
		} else if (x.first[0] == 0) {
			d[x.first[1]] += x.second;
		} else if (x.first[0] == x.first[2]) {
			d[n] += x.second;
		} else {
			d[x.first[0]] += x.second;
		}
	}
	double e = 0;
	for (int i = 2; i < n; ++ i) e += d[i] * memo[i];
	return (e + 1) / (1 - d[n]);
}
int main() {
	int N;
	cin >> N;
	for (int i = 2; i <= N; ++ i) {
		memo[i] = f(i);
	}
	printf("%.7f\n", memo[N]);
}
