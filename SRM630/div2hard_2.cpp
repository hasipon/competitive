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
	bool func(string s) {
		auto a = SA(s);
		for (int i = 0; i < s.length(); ++ i) if (s[i] != 'a') {
			string t = s;
			-- t[i];
			if (a == SA(t)) return true;
		}
		return false;
	}
	string smallerOne(string s) {
		return func(s) ? "Exists" : "Does not exist";
	}
};
