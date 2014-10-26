#include <bits/stdc++.h>
using namespace std;
int L;
int a[3][26];
bool visited[26][100000];
bool memo[26][100000];
bool f(int p, int q, int r) {
	if (p == 26) return true;
	if (visited[p][q]) return memo[p][q];
	visited[p][q] = true;
	for (int i = 0; i <= a[2][p] && i <= a[0][p]; ++ i) {
		int j = a[2][p] - i;
		if (j <= a[1][p] && q+i <= L && r+j <= L) {
			if (f(p+1, q+i, r+j)) return memo[p][q] = true;
		}
	}
	return memo[p][q] = false;
}
int main() {
	string s1, s2, s3;
	cin >> s1 >> s2 >> s3;
	L = s1.length()/2;
	for (int i = 0; i < s1.length(); ++ i) {
		++ a[0][s1[i]-'A'];
		++ a[1][s2[i]-'A'];
		++ a[2][s3[i]-'A'];
	}
	cout << (f(0, 0, 0) ? "YES" : "NO") << endl;
}
