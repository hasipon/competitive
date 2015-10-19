#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
struct ThePermutationGame {
	int findMin(int N) {
		long r = 1;
		vector<bool> a(N+1);
		for (int i = 2; i*i <= N; ++ i) {
			for (int k = i*i; k <= N; k += i) a[k] = true;
		}
		for (int i = 2; i <= N; ++ i) if (!a[i]) {
			long x = 1;
			for (;;) {
				x *= i;
				if (x > N) break;
				r = r * i % mod;
			}
		}
		return r;
	}
};
