#include <bits/stdc++.h>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<long> A(N), B(N);
	for (int i = 0; i < N; ++ i) cin >> A[i];
	for (int i = 0; i < N; ++ i) cin >> B[i];
	long r = B[0] * N;
	long x = 0;
	long y = B[0];
	long p = 0;
	long z = N;
	for (int i = 0; i < N; ++ i) {
		x += A[i];
		-- z;
		if (p + x < 0) {
			if (y <= 0) break;
			long t = (-(x+p)+y-1)/y;
			p += t * y;
			z -= t;
			if (z < 0) break;
		}
		if (i+1 < N) y = max(y, B[i+1]);
		r = max(r, p + x + z * y);
	}
	cout << r << endl;
}
