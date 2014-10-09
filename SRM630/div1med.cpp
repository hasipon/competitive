#include <bits/stdc++.h>
using namespace std;
struct SuffixArrayDiv1 {
	int minimalCharacters(vector <int> a) {
		int n = a.size();
		vector<int> z(n+1, -1);
		for (int i = 0; i < n; ++ i) z[a[i]] = i;
		z.erase(z.begin());
		int r = 1;
		for (int i = 1; i < n; ++ i) {
			r += (z[a[i-1]] < z[a[i]] ? 0 : 1);
		}
		return r;
	}
};
