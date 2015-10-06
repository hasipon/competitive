#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int main() {
	int n;
	cin >> n;
	long long x = 1, y = 0;
	for (int i = 0; i < n; ++ i) {
		long long xx = (x*7) % mod;
		long long yy = (x*20+y*27) % mod;
		x = xx; y = yy;
	}
	cout << y << endl;
}
