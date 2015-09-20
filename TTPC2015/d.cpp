#include <bits/stdc++.h>
using namespace std;
bool isPrime(long n) {
	if (n < 2) return false;
	if (n == 2) return true;
	if (n % 2 == 0) return false;
	for (long i = 3; i*i <= n; i += 2) if (n % i == 0) return false;
	return true;
}
int main() {
	string S;
	cin >> S;
	map<char, int> a;
	for (char c : S) {
		if (!a.count(c)) {
			int n = a.size();
			a[c] = n;
		}
	}
	if (a.size() >= 6) {
		cout << -1 << endl;
		return 0;
	}
	vector<char> b {'1','3','5','7','9'};
	do {
		string s;
		for (char c : S) {
			s += b[a[c]];
		}
		if (isPrime(atol(s.c_str()))) {
			cout << s << endl;
			return 0;
		}
	} while (next_permutation(b.begin(), b.end()));
	cout << -1 << endl;
	return 0;
}
