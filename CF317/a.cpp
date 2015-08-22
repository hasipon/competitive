#include <bits/stdc++.h>
using namespace std;
long long f(long long a, long long l) {
	long long x = min(l, a);
	if (x < 0) return 0;
	return (x+1) * (x+2) / 2;
}
int main() {
	long long a, b, c, l;
	cin >> a >> b >> c >> l;
	long long r = 0;
	for (int i = 0; i <= l; ++ i) {
		r += (l - i + 1) * (l - i + 2) / 2;
	}
	for (int i = 0; i <= l; ++ i) {
		r -= f(a + i - b - c, l-i);
		r -= f(b + i - a - c, l-i);
		r -= f(c + i - a - b, l-i);
	}
	cout << r << endl;
}
