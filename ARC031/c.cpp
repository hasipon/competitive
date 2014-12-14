#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++ i) cin >> a[i];
	vector<long long> c1(n), c2(n);
	{
		vector<int> b;
		b.reserve(n);
		for (int i = 0; i < n; ++ i) {
			auto it = upper_bound(b.begin(), b.end(), a[i]);
			c1[i] = b.end() - it;
			b.insert(it, a[i]);
		}
	}
	{
		vector<int> b;
		b.reserve(n);
		for (int i = n-1; i >= 0; -- i) {
			auto it = upper_bound(b.begin(), b.end(), a[i]);
			c2[i] = b.end() - it;
			b.insert(it, a[i]);
		}
	}
	long long r = 0;
	for (int i = 0; i < n; ++ i) {
		r += min(c1[i], c2[i]);
	}
	cout << r << endl;
}
