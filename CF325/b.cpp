#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n-1);
	vector<int> b(n);
	vector<int> c(n-1);
	for (int i = 0; i < n-1; ++ i) cin >> a[i];
	for (int i = 0; i < n-1; ++ i) cin >> c[i];
	for (int i = 0; i < n; ++ i) cin >> b[i];
	vector<int> d(n);
	for (int i = 0; i < n; ++ i) {
		d[i] = b[i];
		for (int j = 0; j < i; ++ j) d[i] += a[j];
		for (int j = i; j < n-1; ++ j) d[i] += c[j];
	}
	sort(d.begin(), d.end());
	cout << d[0] + d[1] << endl;
}
