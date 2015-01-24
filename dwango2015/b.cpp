#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	s += '$';
	int st = 0;
	long long r = 0, cnt = 0;
	for (int p = 0; p < s.length(); ++ p) {
		if (s[p] == '2') {
			if (st == 1 && cnt > 0) {
				r += cnt * (cnt + 1) / 2;
				cnt = 0;
			}
			st = 1;
		} else if (s[p] == '5') {
			if (st == 0 && cnt > 0) {
				r += cnt * (cnt + 1) / 2;
				cnt = 0;
			} else if (st == 1) {
				++ cnt;
				st = 0;
			}
		} else {
			if (cnt > 0) {
				r += cnt * (cnt + 1) / 2;
				cnt = 0;
			}
			st = 0;
		}
	}
	cout << r << endl;
}
