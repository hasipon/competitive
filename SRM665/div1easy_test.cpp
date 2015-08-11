#include <bits/stdc++.h>
using namespace std;
const long long INF = 1LL << 60;
struct LuckySum {
	string note;
	long long r;
	void f(int p, long long q, int carry, long long d, int z) {
		if (p == note.length()) {
			if (carry == 0) r = min(r, q);
			return;
		}
		// 0
		if (carry && (note[p] == '1' || note[p] == '?') && p+1 == note.length()) {
			f(p+1, q, 0, d*10, 1);
		}
		// 4
		if (p) if ((note[p] == '4' && carry == 0) || (note[p] == '5' && carry == 1) || note[p] == '?') {
			f(p+1, q + 4*d, 0, d*10, 1);
		}
		// 7
		if (p) if ((note[p] == '7' && carry == 0) || (note[p] == '8' && carry == 1) || note[p] == '?') {
			f(p+1, q + 7*d, 0, d*10, 1);
		}
		if (z) return;
		// 4+4 = 8
		if ((note[p] == '8' && carry == 0) || (note[p] == '9' && carry == 1) || note[p] == '?') {
			f(p+1, q + 8*d, 0, d*10, 0);
		}
		// 4+7 = 11
		if ((note[p] == '1' && carry == 0) || (note[p] == '2' && carry == 1) || note[p] == '?') {
			f(p+1, q + 11*d, 1, d*10, 0);
		}
		// 7+7 = 14
		if ((note[p] == '4' && carry == 0) || (note[p] == '5' && carry == 1) || note[p] == '?') {
			f(p+1, q + 14*d, 1, d*10, 0);
		}
	}
	long long construct(string note_) {
		note = note_;
		reverse(note.begin(), note.end());
		r = INF;
		f(0, 0, 0, 1, 0);
		return r == INF ? -1 : r;
	}
};
long long naive(string s) {
	vector<long> a;
	for (int i = 1; i <= 5; ++ i) {
		for (int j = 0; j < (1<<i); ++ j) {
			long x = 0;
			for (int k = 0; k < i; ++ k) x = x*10 + (((j>>k)&1) ? 7 : 4);
			a.push_back(x);
		}
	}
	long r = INF;
	for (long x : a) for (long y : a) {
		string t = to_string(x + y);
		if (s.length() == t.length()) {
			for (int i = 0; i < s.length(); ++ i) {
				if (s[i] != '?' && s[i] != t[i]) goto next;
			}
			r = min(r, x + y);
			next:;
		}
	}
	return r == INF ? -1 : r;
}
bool test(string t) {
	LuckySum L;
	long long r1 = L.construct(t);
	long long r2 = naive(t);
	if (r1 != r2) {
		cerr << endl;
		cout << t << " " << r1 << " " << r2 << endl;
		return true;
	}
	return false;
}
int main() {
	test("?");
	test("?1");
	test("4?8");
	test("2??");
	/*string s;
	while (cin >> s) {
		LuckySum x;
		cout << x.construct(s) << " " << naive(s) << endl;
	}*/
	for (int i = 1; i < 100000; ++ i) {
		string t;
		int x = i;
		while (x) {
			if (x % 11 == 10) {
				t = "?" + t;
			} else {
				t = to_string(x % 11) + t;
			}
			x /= 11;
		}
		cerr << t << "\r" << flush;
		if (test(t)) break;
	}
}
