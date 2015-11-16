#include <bits/stdc++.h>
using namespace std;
int main() {
	long long x, y;
	cin >> x >> y;
	if (__gcd(x, y) == 1) {
		while (x > 1 || y > 1) {
			if (x > y) {
				long long n = (x-1)/y;
				cout << n << "A";
				x -= n*y;
			} else {
				long long n = (y-1)/x;
				cout << n << "B";
				y -= n*x;
			}
		}
		cout << endl;
	} else {
		cout << "Impossible" << endl;
	}
}
