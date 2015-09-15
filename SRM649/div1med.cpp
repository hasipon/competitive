#include <bits/stdc++.h>
using namespace std;
struct XorSequence {
	long long getmax(int N, int sz, int A0, int A1, int P, int Q, int R) {
		vector<long long> A(sz);
		A[0] = A0;
		A[1] = A1;
		for (int i = 2; i < sz; ++ i) {
			A[i] = (A[i - 2] * P + A[i - 1] * Q + R) % N;
		}
		long long r = 0;
		for (int i = 29; i >= 0; -- i) {
			unordered_map<long long, int> s;
			long long r0 = 0, r1 = 0;
			for (long long x : A) {
				long long y = x >> i;
				++ s[y];
				if (y&1) r0 += s[y^1]; else r1 += s[y^1];
			}
			r += max(r0, r1);
		}
		return r;
	}
};
