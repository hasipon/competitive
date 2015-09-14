#include <bits/stdc++.h>
using namespace std;
map<int, int> A;
vector<pair<int,int>> B;
long long g(int c) {
	return 1;
}
long long f() {
	if (A.empty()) return 0;
	B.clear();
	for (auto x : A) B.push_back(x);
	long long r = 1LL << 60;
	r = min(r, g(B[0].second));
	r = min(r, g(B.back().second));
	return r;
}
int main() {
	int N;
	cin >> N;
	if (N > 2000) throw 1;
	for (int i = 0; i < N; ++ i) {
		int x, a;
		cin >> x >> a;
		A[x] = a;
	}
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++ i) {
		int c, y, b;
		cin >> c >> y >> b;
		if (c == 1) {
			A[y] = b;
		} else {
			A.erase(y);
		}
		cout << f() << endl;
	}
}
