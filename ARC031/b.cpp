#include <bits/stdc++.h>
using namespace std;
void f(vector<string>& a, int i, int j) {
	if (0 <= i && i < 10 && 0 <= j && j < 10) if (a[i][j] == 'o') {
		a[i][j] = 'x';
		f(a, i+1, j);
		f(a, i-1, j);
		f(a, i, j+1);
		f(a, i, j-1);
	}
}
bool check(vector<string> a) {
	for (int i = 0; i < 10; ++ i) for (int j = 0; j < 10; ++ j) if (a[i][j] == 'o') {
		f(a, i, j);
		for (int k = 0; k < 10; ++ k) for (int l = 0; l < 10; ++ l) if (a[k][l] == 'o') return false;
		return true;
	}
	throw 1;
}
int func(vector<string> a) {
	for (int i = 0; i < 10; ++ i) for (int j = 0; j < 10; ++ j) {
		vector<string> b = a;
		b[i][j] = 'o';
		if (check(b)) return true;
	}
	return false;
}
int main() {
	vector<string> a(10);
	for (int i = 0; i < 10; ++ i) cin >> a[i];
	cout << (func(a) ? "YES" : "NO") << endl;
}
