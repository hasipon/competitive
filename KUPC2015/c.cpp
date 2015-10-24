#include <bits/stdc++.h>
using namespace std;
bool f() {
	int N;
	cin >> N;
	vector<vector<int>> a(N, vector<int>(N));
	for (int i = 0; i < N; ++ i) for (int j = 0; j < N; ++ j) {
		cin >> a[i][j];
		if (a[i][j] == -1) a[i][j] = 1<<29;
	}
	for (int i = 0; i < N; ++ i) if (a[i][i] != 0) return false;
	auto b = a;
	for (int k = 0; k < N; ++ k) for (int i = 0; i < N; ++ i) for (int j = 0; j < N; ++ j) {
		a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
	}
	return a == b;
}
int main() {
	int T;
	cin >> T;
	for (int tt = 0; tt < T; ++ tt) {
		cout << (f() ? "YES" : "NO") << endl;
	}
}
