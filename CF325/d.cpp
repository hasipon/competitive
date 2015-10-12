#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	for (int tt = 0; tt < T; ++ tt) {
		int n, k;
		cin >> n >> k;
		vector<string> a(3);
		cin >> a[0] >> a[1] >> a[2];
		int x = 0;
		if (a[0][0] == 's') { x |= 1; a[0][0] = '.'; }
		if (a[1][0] == 's') { x |= 2; a[1][0] = '.'; }
		if (a[2][0] == 's') { x |= 4; a[2][0] = '.'; }
		for (int k = 0; k < 3; ++ k) if (a[k][1] != '.') {
			x &= ~(1<<k);
		}
		for (int i = 1; i < n && x; i += 3) {
			if ((x&1) && a[1][i] == '.') x |= 2;
			if ((x&2) && a[0][i] == '.') x |= 1;
			if ((x&2) && a[2][i] == '.') x |= 4;
			if ((x&4) && a[1][i] == '.') x |= 2;
			for (int j = i+1; j < n && j <= i+3; ++ j) {
				for (int k = 0; k < 3; ++ k) if (a[k][j] != '.') {
					x &= ~(1<<k);
				}
			}
		}
		cout << (x ? "YES" : "NO") << endl;
	}
}
