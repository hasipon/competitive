#include <bits/stdc++.h>
using namespace std;
struct BuildingTowersEasy {
	int maxHeight(int N, vector <int> x, vector <int> t) {
		int rr = 0;
		for (int i = 0; i < N; ++ i) {
			int r = i;
			for (int j = 0; j < x.size(); ++ j) {
				r = min(r, t[j] + abs(x[j]-1 - i));
			}
			rr = max(rr, r);
		}
		return rr;
	}
};
