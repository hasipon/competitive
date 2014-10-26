#include <bits/stdc++.h>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; ++ i) cin >> a[i];
	map<int, vector<int>> b;
	for (int i = 0; i < N; ++ i) {
		b[-a[i]].push_back(i);
	}
	set<int> c;
	c.insert(-1);
	c.insert(N);
	vector<int> res(N);
	for (const auto& x : b) {
		const auto& d = x.second;
		for (int y : d) {
			auto i = c.upper_bound(y);
			auto j = i;
			-- j;
			res[y] = *i - *j - 2;
		}
		for (int y : d) c.insert(y);
	}
	for (int x : res) {
		cout << x << endl;
	}
}
