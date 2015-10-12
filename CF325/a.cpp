#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++ i) cin >> a[i];
	for (int i = 0; i+2 < n; ++ i) if (a[i] && !a[i+1] && a[i+2]) {
		a[i+1] = 1;
	}
	int s = 0;
	for (int x : a) s += x;
	cout << s << endl;
}
