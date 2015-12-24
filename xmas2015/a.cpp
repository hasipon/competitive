#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> P;
int N, X, T;
long long A, B, C;
P mul(P x, P y) {
	return {x.first * y.first % C, (x.first * y.second + x.second) % C};
}
P pow(P x, int n) {
	if (n == 0) return {1, 0};
	if (n == 1) return x;
	auto p = pow(x, n/2);
	auto q = mul(p, p);
	if (n % 2 == 0) return q; else return mul(q, x);
}
int main() {
	cin >> N >> X >> T >> A >> B >> C;
	auto p = pow({A, B}, T);
	long long D = p.first, E = p.second;
	long long sum = 0;
	for (int i = 0; i < N; ++ i) {
		sum += X;
		X = (D * X + E) % C;
	}
	cout << sum << endl;
}
