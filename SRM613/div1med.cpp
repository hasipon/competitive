#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
struct RandomGCD {
	map<pair<int,int>, int> memo;
	int N;
	int pow(long long n, int k) {
		long long r = 1;
		while (k > 0) {
			if (k & 1) r = r * n % mod;
			n = n * n % mod;
			k >>= 1;
		}
		return r;
	}
	int f(int low, int high) {
		if (low > high) return 0;
		if (memo.count(make_pair(low, high))) return memo[make_pair(low, high)];
		int s = high - low + 1;
		long long r = pow(s, N);
		for (int i = 2; i <= high; ++ i) {
			if (i > s && i < low) i = low;
			r = (r - g(i, low, high) + mod) % mod;
		}
		return memo[make_pair(low, high)] = r;
	}
	int g(int K, int low, int high) {
		return f((low + K - 1) / K, high / K);
	}
	int countTuples(int N_, int K, int low, int high) {
		N = N_;
		return g(K, low, high);
	}
};
