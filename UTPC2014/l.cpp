#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
int f(int p) {
	int r = 0;
	for (auto x : a) {
		if (((p >> x[0]) ^ (p >> x[1])) & 1) -- r; else ++ r;
	}
	return r;
}
int main() {
	string P;
	cin >> P;
	int cnt = 0;
	map<char, int> m;
	for (unsigned i = 0; i < P.length(); i += 2) {
		if (!m.count(P[i])) m[P[i]] = cnt++;
	}
	if (cnt > 20) throw 1;
	for (unsigned i = 0; i < P.length(); i += 4) {
		a.push_back(vector<int>{m[P[i]], m[P[i+2]]});
	}
	int mm = 1<<30;
	int r = 0;
	for (int i = 0; i < 1<<cnt; ++ i) {
		int x = f(i);
		if (x < mm) {
			mm = x;
			r = 1;
		} else if (x == mm) {
			++ r;
		}
	}
	cout << r << endl;
}
