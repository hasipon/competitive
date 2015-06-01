#include <bits/stdc++.h>
using namespace std;
struct TheKingsFactorization {
	vector<long long> getVector(long long N, vector<long long> primes) {
		vector<long long> res;
		for (int i = 0; i < primes.size(); ++ i) {
			res.push_back(primes[i]);
			N /= primes[i];
			if (N <= 1) break;
			if (i == primes.size()-1) break;
			if (i == primes.size()-2 && N / primes[i+1] <= primes[i+1]) {
				long long j = N / primes[i+1];
				N /= j;
				res.push_back(j);
			} else for (int j = primes[i]; ; ++ j) {
				if (N % j == 0) {
					N /= j;
					res.push_back(j);
					break;
				}
			}
		}
		if (N > 1) res.push_back(N);
		return res;
	}
};
