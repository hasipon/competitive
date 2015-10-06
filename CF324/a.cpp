#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, t;
	cin >> n >> t;
	if (n == 1) {
		if (t == 10) {
			cout << -1 << endl;
		} else {
			cout << t << endl;
		}
	} else {
		char buf[1000];
		buf[0] = '1';
		int x = 1;
		for (int i = 1; i < n; ++ i) {
			buf[i] = '0';
			x = x * 10 % t;
		}
		if (x) {
			buf[n-1] = '0' + (t-x);
		}
		buf[n] = 0;
		cout << buf << endl;
	}
}
