#include <bits/stdc++.h>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	if (N > 10) throw 1;
	vector<int> S(N);
	for (int& x : S) cin >> x;
	vector<int> T(M);
	for (int& x : T) cin >> x;
	vector<vector<int>> A(N);
	for (int i = 0; i < N; ++ i) {
		int K;
		cin >> K;
		A[i].resize(K);
		for (int& x : A[i]) cin >> x;
	}
	double r = 0;
	for (int i = 1; i < 1<<N; ++ i) {
		set<int> a;
		double s = 0;
		double t = 0;
		for (int j = 0; j < N; ++ j) if ((i>>j)&1) {
			s += S[j];
			for (int x : A[j]) a.insert(x);
		}
		for (int x : a) t += T[x-1];
		r = max(r, s / t);
	}
	cout << r << endl;
}
