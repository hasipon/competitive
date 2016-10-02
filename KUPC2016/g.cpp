#include <bits/stdc++.h>
using namespace std;
string s;
int f(int n) {
	set<pair<long long, long long>> S;
	int h1 = 0, t1 = 1;
	int h2 = 0, t2 = 1;
	for (int i = 0; i < n; ++ i) {
		h1 = h1*37+s[i];
		t1 = t1*37;
		h2 = h2*31+s[i];
		t2 = t2*31;
	}
	S.insert({h1,h2});
	for (int i = n; i < s.length(); ++ i) {
		h1 = h1 * 37 - t1 * s[i-n] + s[i];
		h2 = h2 * 31 - t2 * s[i-n] + s[i];
		S.insert({h1,h2});
	}
	return S.size();
}

int main() {
	cin >> s;
	int x0 = 1, x3 = s.length();
	while (x3 - x0 > 3) {
		int x1 = (x0*2 + x3) / 3;
		int x2 = (x0 + x3*2) / 3;
		if (f(x1) < f(x2)) x0 = x1; else x3 = x2;
	}
	int r = 0;
	for (int i = x0; i <= x3; ++ i) {
		r = max(r, f(i));
	}
	cout << r << endl;
}
