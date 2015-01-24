#include <bits/stdc++.h>
using namespace std;
string s, t;
bool visited[5000][5000];
bool memo[5000][5000];
bool f(int x, int y) {
	if (x == s.length()) return y == t.length();
	if (y == t.length()) return false;
	if (s[x] != t[y]) return false;
	if (visited[x][y]) return memo[x][y];
	visited[x][y] = true;
	if (f(x+1, y+1)) return memo[x][y] = true;
	if (y+1 < t.length() && t[y] != t[y+1]) {
		for (int i = y+2; i <= t.length(); ++ i) {
			if (f(x+1, i)) return memo[x][y] = true;
		}
	}
	return false;
}
int main() {
	cin >> s >> t;
	cout << (f(0, 0) ? "Yes" : "No") << endl;
}
