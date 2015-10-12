#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> v, d, p;
vector<int> a, r;
int main() {
	cin >> n;
	v.resize(n);
	d.resize(n);
	p.resize(n);
	for (int i = 0; i < n; ++ i) cin >> v[i] >> d[i] >> p[i];
	a = p;
	for (int i = 0; i < n; ++ i) if (a[i] >= 0) {
		r.push_back(i);
		int vi = v[i];
		vector<int> b;
		for (int j = i+1; j < n && vi > 0; ++ j) if (a[j] >= 0) {
			a[j] -= vi;
			-- vi;
			if (a[j] < 0) b.push_back(j);
		}
		for (int j = 0; j < b.size(); ++ j) {
			for (int k = b[j]+1; k < n; ++ k) if (a[k] >= 0) {
				a[k] -= d[b[j]];
				if (a[k] < 0) b.push_back(k);
			}
		}
	}
	cout << r.size() << endl;
	for (int i = 0; i < r.size(); ++ i) {
		if (i) cout << " ";
		cout << r[i] + 1;
	}
	cout << endl;
}
