#include <bits/stdc++.h>
using namespace std;
int f(int x) {
	if (x == 1) return false;
	for (int i = 2; i*i <= x; ++ i) if (x % i == 0) return false;
	return true;
}
int main() {
	int n;
	cin >> n;
	int m = 0;
	for (int i = 1; i <= n; ++ i) m += i;
	cout << (f(m) ? "WANWAN" : "BOWWOW") << endl;
}
