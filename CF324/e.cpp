#include <bits/stdc++.h>
using namespace std;
int main() { ios::sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> p(n), s(n);
	for (int i = 0; i < n; ++ i) cin >> p[i];
	for (int i = 0; i < n; ++ i) cin >> s[i];
	map<int,int> m;
	for (int i = 0; i < n; ++ i) m[s[i]] = i;
	vector<int> t(n);
	for (int i = 0; i < n; ++ i) {
		t[i] = m[p[i]];
	}
	int r = 0;
	vector<pair<int,int>> sw;
	for (int i = n-1; i > 0; -- i) {
		for (int j = 0; j < n; ++ j) if (t[j] == i) {
			while (j < i) {
				int p1 = j;
				int p2 = i;
				while (!(t[p2] <= p1)) -- p2;
				r += p2-p1;
				sw.push_back({p1,p2});
				swap(t[p1], t[p2]);
				j = p2;
			}
			break;
		}
	}
	cout << r << endl;
	cout << sw.size() << endl;
	for (auto x : sw) cout << x.first+1 << " " << x.second+1 << endl;
}
