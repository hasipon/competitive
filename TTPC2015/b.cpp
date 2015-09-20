#include <bits/stdc++.h>
using namespace std;
int main() {
	int N, B, C;
	cin >> N >> B >> C;
	vector<int> A(N);
	for (int i = 0; i < N; ++ i) cin >> A[i];
	int r = 0;
	for (int i = N-1; i >= 0; -- i) {
		int x = min(C, B);
		r += A[i] * x;
		C -= x;
	}
	cout << r << endl;
}
