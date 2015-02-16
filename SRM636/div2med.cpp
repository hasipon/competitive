#include <bits/stdc++.h>
using namespace std;
struct SortishDiv2 {
	int f(vector <int> a) {
		int r = 0;
		for (int i = 0; i < a.size(); ++ i) {
			for (int j = i+1; j < a.size(); ++ j) {
				if (a[i] < a[j]) ++ r;
			}
		}
		return r;
	}
	int ways(int sortedness, vector <int> seq) {
		vector<int> a;
		set<int> b;
		for (int i = 0; i < seq.size(); ++ i) {
			if (seq[i] == 0) a.push_back(i); else b.insert(seq[i]);
		}
		if (a.empty()) return f(seq) == sortedness ? 1 : 0;
		vector<int> c;
		for (int i = 1; i <= seq.size(); ++ i) {
			if (!b.count(i)) c.push_back(i);
		}
		int r = 0;
		do {
			vector<int> d = seq;
			for (int i = 0; i < c.size(); ++ i) d[a[i]] = c[i];
			if (f(d) == sortedness) ++ r;
		} while (next_permutation(c.begin(), c.end()));
		return r;
	}
};
