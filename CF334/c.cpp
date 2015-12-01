#include <bits/stdc++.h>
using namespace std;
bool k_odd;
int grundy(int x) {
	if (x == 0) return 0;
	if (x % 2 == 1 && x >= 15) return 0;
	bool s[3] = {};
	s[grundy(x-1)] = true;
	if (x % 2 == 0) {
		if (k_odd) s[grundy(x/2)] = true;
		else s[0] = true;
	}
	for (int i = 0; ; ++ i) if (!s[i]) return i;
}
int main() {
	int n, k;
	cin >> n >> k;
	k_odd = (k % 2 != 0);
	int g = 0;
	for (int i = 0; i < n; ++ i) {
		int ai;
		cin >> ai;
		g ^= grundy(ai);
	}
	cout << (g == 0 ? "Nicky" : "Kevin") << endl;
}
