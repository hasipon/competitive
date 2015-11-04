#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; ++ i) cin >> a[i];
	map<string, int> cnt;
	for (auto x : a) {
		int len = x.length();
		sort(x.begin(), x.end());
		x.erase(unique(x.begin(), x.end()), x.end());
		cnt[x] += len;
	}
	int res = 0;
	for (char a = 'a'; a <= 'z'; ++ a) {
		int r = cnt[string("") + a];
		res = max(res, r);
		for (char b = a+1; b <= 'z'; ++ b) {
			int rr = r + cnt[string("") + b] + cnt[string("") + a + b];
			res = max(res, rr);
		}
	}
	cout << res << endl;
}
