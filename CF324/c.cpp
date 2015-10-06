#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, t;
	string s1, s2;
	cin >> n >> t >> s1 >> s2;
	int x = 0;
	for (int i = 0; i < n; ++ i) {
		if (s1[i] == s2[i]) ++ x;
	}
	for (int a = 0; a <= x; ++ a) {
		int c = n-t-a;
		if (2*c <= n-x) {
			string s3;
			int d = c;
			for (int i = 0; i < n; ++ i) {
				if (s1[i] == s2[i]) {
					if (a) {
						s3 += s1[i];
						-- a;
					} else {
						for (char ch = 'a'; ch <= 'z'; ++ ch) if (ch != s1[i]) {
							s3 += ch;
							break;
						}
					}
				} else {
					if (c) {
						s3 += s1[i];
						-- c;
					} else if (d) {
						s3 += s2[i];
						-- d;
					} else {
						for (char ch = 'a'; ch <= 'z'; ++ ch) if (ch != s1[i] && ch != s2[i]) {
							s3 += ch;
							break;
						}
					}
				}
			}
			cout << s3 << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}
