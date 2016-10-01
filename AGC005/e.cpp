#include <bits/stdc++.h>
using namespace std;
int N, M;
map<int,int> a;
bool g(int L) {
	vector<int> c(L);
	int mi = 1<<30, ma = -1;
	for (int i = 0; i < L; ++ i) {
		c[i] = max(i, L-1-i);
		mi = min(mi, c[i]);
		ma = max(ma, c[i]);
	}
	auto b = a;
	for (int x : c) {
		if (b[x] == 0) return false;
		-- b[x];
	}
	for (auto p : b) {
		if (p.second == 0) continue;
		if (!(mi < p.first && p.first <= ma)) return false;
	}
	return true;
}
bool f() {
	for (int l = M+1; l <= N; ++ l) {
		if (g(l)) return true;
	}
	return false;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; ++ i) {
		int x;
		cin >> x;
		++ a[x];
		M = max(M, x);
	}
	cout << (f() ? "Possible" : "Impossible") << endl;
}
