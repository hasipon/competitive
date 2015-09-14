#include <bits/stdc++.h>
using namespace std;
int main() {
	long A, B, X;
	cin >> A >> B >> X;
	if (A >= 1024 || B >= 1024 || X >= 1024) throw 1;
	set<long> s;
	s.insert(A);
	for (int t = 0; ; ++ t) {
		if (A == X) {
			cout << t << endl;
			break;
		}
		if (A & 1) {
			A /= 2;
			A ^= B;
		} else {
			A /= 2;
		}
		if (!s.insert(A).second) {
			cout << -1 << endl;
			break;
		}
	}
}
