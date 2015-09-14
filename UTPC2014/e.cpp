#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	unordered_map<int, long long> a0;
	unordered_map<int, long long> a;
	long long r = 0;
	for (int i = 0; i < n; ++ i) {
		int s;
		long long b;
		cin >> s >> b;
		a0[s] += b;
		r = max(r, a[s] += b);
		for (int j = 1; j <= s.length(); ++ j) {
			string t = s.substr(j);
			long long rr = -1;
			for (char c = '0'; c <= '9'; ++ c) {
				string tt = c + s.substr(j);
				if (a.count(tt)) rr = max(rr, a[tt]);
			}
			if (rr + a0[t] < a[t]) break;
			r = max(r, a[t] = rr + a0[t]);
		}
		cout << r << endl;
	}
}
