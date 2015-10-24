#include <bits/stdc++.h>
using namespace std;
int N;
char buf[300][300];
int main() {
	while (cin >> N) {
		vector<int> s(N);
		for (int& x : s) cin >> x;
		vector<string> a(N);
		for (string& x : a) cin >> x;
		vector<string> b = a;
		for (int x = 0; x < N; ++ x) {
			for (int y = 0; y <= x; ++ y) {
				int i = N-1-x+y;
				int j = y;
				if (s[i] < s[j]) b[x][y] = a[N-1-(s[j]-1)+(s[i]-1)][s[i]-1];
				else             b[x][y] = a[N-1-(s[i]-1)+(s[j]-1)][s[j]-1];
			}
		}
		for (auto x : b) cout << x << endl;
	}
}
