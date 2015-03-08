#include <bits/stdc++.h>
using namespace std;
struct NarrowPassage2Easy {
	vector <int> c;
	int N, S;
	set<vector<int>> r;
	void f(vector<int> a) {
		if (!r.insert(a).second) return;
		for (int i = 1; i < N; ++ i) {
			if (c[a[i]] + c[a[i-1]] <= S) {
				vector<int> b = a;
				swap(b[i], b[i-1]);
				f(b);
			}
		}
	}
	int count(vector <int> size, int maxSizeSum) {
		c = size;
		N = size.size();
		S = maxSizeSum;
		vector<int> a(N);
		for (int i = 0; i < N; ++ i) a[i] = i;
		f(a);
		return r.size();
	}
};
