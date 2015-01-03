#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
int comb[100][100];
struct OkonomiyakiParty {
	int f(int x, int y) {
		if (x < y) return 0;
		return comb[x][y];
	}
	int count(vector <int> osize, int M, int K) {
		for (int i = 0; i < 100; ++ i) {
			comb[i][0] = comb[i][i] = 1;
			for (int j = 1; j < i; ++ j) comb[i][j] = (comb[i-1][j-1] + comb[i-1][j]) % mod;
		}
		sort(osize.begin(), osize.end());
		int r = 0;
		for (int i = 0; i < osize.size(); ++ i) {
			int n = (upper_bound(osize.begin(), osize.end(), osize[i] + K) - osize.begin()) - i;
			r += f(n-1, M-1);
			r %= mod;
		}
		return r;
	}
};
