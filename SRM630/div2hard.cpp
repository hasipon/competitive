#include <bits/stdc++.h>
using namespace std;
struct SuffixArrayDiv2 {
	vector<int> SA(string s) {
		vector<pair<string, int>> a;
		for (int i = 0; i < s.length(); ++ i) {
			a.push_back(make_pair(s.substr(i), i));
		}
		sort(a.begin(), a.end());
		vector<int> r;
		for (auto x : a) r.push_back(x.second);
		return r;
	}
	string f(const vector<int>& a) {
		int n = a.size();
		vector<int> z(n+1, -1);
		for (int i = 0; i < n; ++ i) z[a[i]] = i;
		z.erase(z.begin());
		string r(n, '?');
		r[a[0]] = 'a';
		for (int i = 1; i < n; ++ i) {
			r[a[i]] = r[a[i-1]] + (z[a[i-1]] < z[a[i]] ? 0 : 1);
		}
		return r;
	}
	string smallerOne(string s) {
		return f(SA(s)) < s ? "Exists" : "Does not exist";
	}
};
