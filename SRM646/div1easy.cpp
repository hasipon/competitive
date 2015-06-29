#include <bits/stdc++.h>
using namespace std;
struct TheConsecutiveIntegersDivOne {
	int find(vector <int> a, int k) {
		sort(a.begin(), a.end());
		int r = 1<<30;
		for (int i = 0; i + k <= a.size(); ++ i) {
			vector<int> b(a.begin() + i, a.begin() + i + k);
			for (int j = 0; j < k; ++ j) {
				int d = b[j] - j;
				int rr = 0;
				for (int x = 0; x < k; ++ x) {
					rr += abs(b[x] - (d + x));
				}
				r = min(r, rr);
			}
		}
		return r;
	}
};
