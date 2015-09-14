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
	random_shuffle(aa.begin(), aa.end());
	map<string, int> b;
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
			b[s] = i;
			break;
		}
	}
	for (int i = 0; i < T; ++ i) {
		cout << b[a[i]] << endl;
	}
}
