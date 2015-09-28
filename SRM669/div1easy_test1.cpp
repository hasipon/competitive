#include <bits/stdc++.h>
using namespace std;
struct SubdividedSlimes {
	long f(int S, int x) {
		long r = 0;
		int s = S / (x+1);
		int m = S % (x+1);
		for (int i = 0; i < x; ++ i) {
			for (int j = i+1; j <= x; ++ j) {
				int s1 = s + (i < m ? 1 : 0);
				int s2 = s + (j < m ? 1 : 0);
				r += s1 * s2;
			}
		}
		return r;
	}
	int needCut(int S, int M) {
		for (int i = 1; i <= S; ++ i) {
			if (f(S, i) >= M) return i;
		}
		return -1;
	}
};
struct SubdividedSlimes2 {
	long f(int S, int x) {
		long r = 0;
		int s = S / (x+1);
		int m = S % (x+1);
		for (int i = 0; i < x; ++ i) {
			for (int j = i+1; j <= x; ++ j) {
				int s1 = s + (i < m ? 1 : 0);
				int s2 = s + (j < m ? 1 : 0);
				r += s1 * s2;
			}
		}
		return r;
	}
	int needCut(int S, int M) {
		for (int i = 1; i < S; ++ i) {
			if (f(S, i) >= M) return i;
		}
		return -1;
	}
};
int main() {
	SubdividedSlimes s;
	SubdividedSlimes2 s2;
	int cnt = 0;
	for (;;) {
		++ cnt;
		int S = rand() % 1000 + 2;
		int M = rand() % 1000 + 2;
		int r1 = s.needCut(S, M);
		int r2 = s2.needCut(S, M);
		if (r1 != r2) {
			cout << S << " " << M << " " << r1 << " " << r2 << endl;
		}
		if (cnt % 256 == 0) cerr << cnt << "\r" << flush;
	}
}