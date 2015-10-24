#include <bits/stdc++.h>
using namespace std;
int f(string s) {
	int r = 0;
	int p = 0;
	for (;;) {
		auto i = s.find("tokyo", p);
		auto j = s.find("kyoto", p);
		if (i == string::npos && j == string::npos) break;
		auto k = min(i, j);
		p = k + 5;
		++ r;
	}
	return r;
}
int main() {
	int T;
	cin >> T;
	for (int tt = 0; tt < T; ++ tt) {
		string s;
		cin >> s;
		cout << f(s) << endl;
	}
}
