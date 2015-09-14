#include <bits/stdc++.h>
using namespace std;
int main() {
	int T;
	cin >> T;
	vector<string> a(T);
	for (int i = 0; i < T; ++ i) {
		cin >> a[i];
	}
	vector<string> aa = a;
	sort(aa.begin(), aa.end());
	aa.erase(unique(aa.begin(), aa.end()), aa.end());
	int r = 1<<30;
	map<string, int> b;
	int TT = 1;
	if (T == 10000) TT = 100;
	if (T == 30000) TT = 10;
	if (T == 100000) TT = 10;
	for (int tt = 0; tt < TT; ++ tt) {
		map<string, int> bb;
		bb.swap(b);
		random_shuffle(aa.begin(), aa.end());
		int rr = 0;
		for (string s : aa) {
			set<int> ss;
			for (int i = 1; i < 10; ++ i) {
				string t = s;
				swap(t[i], t[i-1]);
				if (b.count(t)) {
					ss.insert(b[t]);
				}
			}
			for (int i = 0; ; ++ i) if (!ss.count(i)) {
				rr = max(rr, b[s] = i);
				break;
			}
		}
		if (rr < r) {
			r = rr;
		} else {
			bb.swap(b);
		}
	}
	for (int i = 0; i < T; ++ i) {
		cout << b[a[i]] << endl;
	}
}
