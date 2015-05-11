#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int S;
struct NarrowPassage2 {
	long f(vector<pair<int,int>> p) {
		if (p.size() <= 1) return 1;
		int a = min_element(p.begin(), p.end()) - p.begin();
		int b = max_element(p.begin(), p.end()) - p.begin();
		if (p[a].first + p[b].first > S) {
			vector<pair<int,int>> q(p.begin(), p.begin() + b);
			vector<pair<int,int>> r(p.begin() + b + 1, p.end());
			return f(q) * f(r) % mod;
		} else {
			vector<pair<int,int>> q = p;
			q.erase(q.begin() + a);
			return f(q) * p.size() % mod;
		}
	}
	int count(vector <int> s, int maxSizeSum) {
		S = maxSizeSum;
		int n = s.size();
		vector<pair<int,int>> a(n);
		for (int i = 0; i < n; ++ i) a[i] = make_pair(s[i], i);
		return f(a);
	}
};
