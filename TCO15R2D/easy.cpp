#include <bits/stdc++.h>
using namespace std;
struct BalancedSubstrings {
	int countSubstrings(string s) {
		int L = s.length();
		int r = 0;
		for (int i = 0; i < L; ++ i) {
			int c = 0;
			for (int j = i; j < L; ++ j) {
				if (s[j] == '1' && ++ c >= 2) break;
				++ r;
			}
		}
		for (int i = 0; i < L; ++ i) {
			map<int, int> a, b;
			for (int j = i-1, c = 0; j >= 0; -- j) {
				if (s[j] == '1') c += i - j;
				++ a[c];
			}
			for (int j = i+1, c = 0; j < L; ++ j) {
				if (s[j] == '1') c += j - i;
				++ b[c];
			}
			for (auto x : a) if (x.first > 0) {
				r += x.second * b[x.first];
			}
		}
		return r;
	}
};
bool check(const string& s) {
	for (int i = 0; i < s.length(); ++ i) {
		int x = 0;
		for (int j = 0; j < s.length(); ++ j) if (s[j] == '1') x += j - i;
		if (x == 0) return true;
	}
	return false;
}
int naive(const string& s) {
	int r = 0;
	for (int i = 0; i < s.length(); ++ i) {
		for (int j = 1; i + j <= s.length(); ++ j) {
			if (check(s.substr(i, j))) ++ r;
		}
	}
	return r;
}
int main() {
	BalancedSubstrings x;
	for (int len = 1; ; ++ len) {
		cout << "\r" << len << flush;
		for (int p = 0; p < 1<<len; ++ p) {
			string s;
			for (int i = 0; i < len; ++ i) s += '0' + ((p>>i)&1);
			int r1 = naive(s);
			int r2 = x.countSubstrings(s);
			if (r1 != r2) {
				cout << s << " " << r1 << " " << r2 << endl;
			}
		}
	}
}