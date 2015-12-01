#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	string s;
	cin >> n >> s;
	s += "$";
	int x = 0, c = 2, r = 0;
	for (int i = 0; i < n; ++ i) {
		++ x;
		if (s[i] != s[i+1]) {
			++ r;
			if (x >= 3 && c == 2) { r += 2; c -= 2; }
			else if (x >= 2 && c >= 1) { ++ r; -- c; }
			x = 0;
		}
	}
	cout << r << endl;
}
