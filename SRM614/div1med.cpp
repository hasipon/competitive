#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
struct CycleColoring {
	int countColorings(vector <int> vertexCount, vector <int> fromVertex, vector <int> toVertex, int K) {
		int S = 1000005;
		vector<long long> a(S), b(S);
		a[0] = 1; b[0] = 0;
		for (int i = 1; i < S; ++ i) {
			a[i] = (b[i-1] * (K-1)) % mod;
			b[i] = (b[i-1] * (K-2) + a[i-1]) % mod;
		}

		int N = vertexCount.size();
		int same = K;
		int diff = 0;
		for (int i = 0; i < N; ++ i) {
			int v0 = toVertex[(i+N-1) % N], v1 = fromVertex[i];
			int L0 = abs(v0 - v1);
			int L1 = vertexCount[i] - abs(v0 - v1);
			long long A = a[L0] * a[L1] % mod;
			long long C = b[L0] * b[L1] % mod;
			long long B = C * (K-1) % mod;
			long long DE = (A + C * (K-2)) % mod;
			int same2 = (same * A + diff * C) % mod;
			int diff2 = (same * B + diff * DE) % mod;
			same = same2;
			diff = diff2;
		}
		return same;
	}
};
