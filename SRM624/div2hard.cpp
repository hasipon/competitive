#include <bits/stdc++.h>
using namespace std;
struct GameOfSegments {
	int winner(int N) {
		vector<int> grundy(N+1);
		for (int i = 0; i <= N; ++ i) {
			set<int> s;
			for (int j = 0; j <= i-2; ++ j) {
				s.insert(grundy[j] ^ grundy[i-2-j]);
			}
			for (int j = 0; ; ++ j) if (!s.count(j)) {
				grundy[i] = j;
				break;
			}
		}
		return grundy[N] ? 1 : 2;
	}
};
