#include <bits/stdc++.h>
using namespace std;
int n, m;
int main() {
	cin >> n >> m;
	vector<vector<pair<int,bool>>> var(m);
	for (int i = 0; i < n; ++ i) {
		int k;
		cin >> k;
		for (int j = 0; j < k; ++ j) {
			int vij;
			cin >> vij;
			if (vij > 0) {
				var[vij-1].push_back({i, true});
			} else {
				var[-vij-1].push_back({i, false});
			}
		}
	}
	vector<int> ans(m);
	vector<bool> sat(n);
	for (int i = 0; i < m; ++ i) {
		if (var[i].size() == 1) {
			if (var[i][0].second) ans[i] = 1;
			sat[var[i][0].first] = true;
		} else if (var[i].size() == 2) {
			if (var[i][0].second == var[i][1].second) {
				if (var[i][0].second) ans[i] = 1;
				sat[var[i][0].first] = sat[var[i][1].first] = true;
			} else {
				
			}
		}
	}
	bool yes = true;
	for (bool x : sat) if (!x) { yes = false; break; }
	if (yes) {
		cout << "YES" << endl;
		for (int x : ans) cout << x;
		cout << endl;
	} else {
		cout << "NO" << endl;
	}
}
