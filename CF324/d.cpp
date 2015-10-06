#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
	if (n < 2) return false;
	if (n == 2) return true;
	for (int i = 3; i*i <= n; i += 2) if (n % i == 0) return false;
	return true;
}
vector<int> g(int n) {
	if (n == 2) return {2};
	if (n == 4) return {2, 2};
	for (int i = 3; ; i += 2) if (isPrime(i) && isPrime(n-i)) {
		return {i, n-i};
	}
}
vector<int> f(int n) {
	if (isPrime(n)) return {n};
	for (int i = 2; ; i += 2) if (isPrime(n-i)) {
		auto r = g(i);
		r.push_back(n-i);
		return r;
	}
}
int main() {
	int n;
	cin >> n;
	auto r = f(n);
	cout << r.size() << endl;
	for (int i = 0; i < r.size(); ++ i) {
		if (i) cout << " ";
		cout << r[i];
	}
	cout << endl;
}
