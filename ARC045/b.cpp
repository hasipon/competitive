#include <bits/stdc++.h>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> s(M), t(M);
	for (int i = 0; i < M; ++ i) cin >> s[i] >> t[i];
	map<int,int> a;
	for (int i = 0; i < M; ++ i) {
		++ a[s[i]];
		-- a[t[i]+1];
	}
	set<int> b;
	int sum = 0;
	for (auto x : a) {
		sum += x.second;
		if (sum == 1) b.insert(x.first);
	}
	vector<int> r;
	for (int i = 0; i < M; ++ i) {
		auto j = b.lower_bound(s[i]);
		auto k = b.lower_bound(t[i]+1);
		if (j == k) r.push_back(i+1);
	}
	cout << r.size() << endl;
	for (int x : r) cout << x << endl;
}
