#include <bits/stdc++.h>
using namespace std;
int f(string s) {
	vector<int> a;
	a.push_back(s[0] - '0');
	for (int i = 2; i < s.length(); i += 2) {
		if (s[i-1] == '+') {
			a.push_back(s[i] - '0');
		} else {
			a.back() *= s[i] - '0';
		}
	}
	int r = 0;
	for (int i = 0; i < a.size(); ++ i) r += a[i];
	return r;
}
int g(string s) {
	int r = s[0] - '0';
	for (int i = 2; i < s.length(); i += 2) {
		if (s[i-1] == '+') {
			r += s[i] - '0';
		} else {
			r *= s[i] - '0';
		}
	}
	return r;
}
int main() {
	string s;
	int n;
	cin >> s >> n;
	int r = 0;
	if (f(s) == n) r += 1;
	if (g(s) == n) r += 2;
	cout << "IMLU"[r] << endl;
}
