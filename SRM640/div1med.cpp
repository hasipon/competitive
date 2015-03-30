#include <bits/stdc++.h>
using namespace std;
struct MaximumBipartiteMatchingProblem {
	long long solve(int n1_, int n2_, int ans_, int d_) {
		long long n1 = n1_, n2 = n2_, ans = ans_, d = d_;
		if (n1 > n2) swap(n1, n2);
		if (n1 == ans) return n1 * n2;
		if (ans < 2*d) return -1;
		return n1 * d + (ans - d) * (n2 - d);
	}
};
