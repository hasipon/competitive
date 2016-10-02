#include <bits/stdc++.h>
using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	vector<int> A(26);
	for (int i = 0; i < N; ++ i) {
		string p;
		cin >> p;
		++ A[p[0]-'A'];
	}
	int r = 0;
	for (;;) {
		sort(A.rbegin(), A.rend());
		int c = K;
		for (int i = 0; i < 26; ++ i) {
			if (A[i] > 0) if (-- A[i], --c == 0) break;
		}
		if (c) break;
		++ r;
	}
	cout << r << endl;
}
