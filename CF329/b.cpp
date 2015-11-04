#include <bits/stdc++.h>
using namespace std;
int n;
int x1, x2;
vector<int> k, b;
bool solve() {
	vector<int> a(n), c(n);
	for (int i = 0; i < n; ++ i) a[i] = i;
	for (int i = 0; i < n; ++ i) c[i] = i;
	sort(a.begin(), a.end(), [&](int i, int j){
		long long yi = (long long)k[i]*x1 + b[i];
		long long yj = (long long)k[j]*x1 + b[j];
		if (yi != yj) return yi < yj; else return k[i] < k[j];
	});
	sort(c.begin(), c.end(), [&](int i, int j){
		long long yi = (long long)k[i]*x2 + b[i];
		long long yj = (long long)k[j]*x2 + b[j];
		if (yi != yj) return yi < yj; else return k[i] > k[j];
	});
	return a != c;
}
int main() {
	scanf("%d", &n);
	k.resize(n);
	b.resize(n);
	scanf("%d%d", &x1, &x2);
	for (int i = 0; i < n; ++ i) scanf("%d%d", &k[i], &b[i]);
	cout << (solve() ? "YES" : "NO") << endl;
}
