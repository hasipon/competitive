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
