#include <bits/stdc++.h>
using namespace std;
string S;
int n;
vector<int> e,c,h;
bool visited[101][50][50];
bool memo[101][50][50];
bool f(int p, int x, int y, int z) {
	if (p == S.length()) return x == 0 && y == 0;
	if (S[p] == 't') {
		if (visited[p][x][y]) return memo[p][x][y];
		visited[p][x][y] = true;
		if (f(p+1, x+1, y, z)) return memo[p][x][y] = true;
		if (y && p < e[z]) {
			if (f(p+1, x, y-1, z+1)) return memo[p][x][y] = true;
		}
		return memo[p][x][y] = false;
	} else if (S[p] == 'i') {
		if (x == 0) return false;
		return f(p+1, x-1, y+1, z);
	} else {
		return f(p+1, x, y, z);
	}
}
bool solve() {
	if (S.length() % 6) return false;
	int nt = 0, ni = 0;
	for (int i = 0; i < S.length(); ++ i) {
		char x = S[i];
		if (x == 't') ++ nt;
		else if (x == 'i') ++ ni;
		else if (x == 'e') e.push_back(i);
		else if (x == 'c') c.push_back(i);
		else if (x == 'h') h.push_back(i);
		else return false;
	}
	n = S.length() / 6;
	if (nt != 2*n) return false;
	if (ni != n) return false;
	if (e.size() != n) return false;
	if (c.size() != n) return false;
	if (h.size() != n) return false;
	for (int i = 0; i < n; ++ i) {
		if (!(e[i] < c[i] && c[i] < h[i])) return false;
	}
	return f(0, 0, 0, 0);
}
int main() {
	cin >> S;
	cout << (solve() ? "Yes" : "No") << endl;
}
