#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	for (int tt = 0; tt < T; ++ tt) {
		int N, D;
		cin >> N >> D;
		for (int i = 1; i < N; ++ i) D ^= 127;
		cout << D + 127 * (N-1) << endl;
	}
}
