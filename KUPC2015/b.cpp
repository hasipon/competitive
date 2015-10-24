#include <bits/stdc++.h>
using namespace std;
vector<string> a, b;
void f(int i, int j) {
	if (0 <= i && i < 10 && 0 <= j && j < 10 && a[i][j] == '.') {
		a[i][j] = 'X';
	}
}
int g(int i, int j) {
	if (!(0 <= i && i < 10)) return 0;
	if (a[i][j] != '.') return 0;
	if (j == 9) return 1;
	int r = 0;
	r += g(i-1, j+1);
	if (r <= 1) r += g(i, j+1);
	if (r <= 1) r += g(i+1, j+1);
	return r;
}
bool check() {
	int r = 0;
	for (int i = 0; i < 10; ++ i) {
		if (r <= 1) r += g(i, 0);
	}
	return r == 1;
}
int main() {
	int cnt = 0;
	for (;;) {
		cerr << ++ cnt << "\r" << flush;
		a = vector<string>(10, string(10, '.'));
		for (int i = 0; i < 5; ++ i) a[rand()%10][rand()%10] = 'C';
		b = a;
		for (int i = 0; i < 10; ++ i) {
			for (int j = 0; j < 10; ++ j) {
				if (a[i][j] == 'C') {
					f(i+1, j);
					f(i+2, j);
					f(i-1, j);
					f(i-2, j);
					f(i, j+1);
					f(i, j+2);
					f(i, j-1);
					f(i, j-2);
					f(i+1, j+1);
					f(i+2, j+2);
					f(i+1, j-1);
					f(i+2, j-2);
					f(i-1, j+1);
					f(i-2, j+2);
					f(i-1, j-1);
					f(i-2, j-2);
				}
			}
		}
		if (check()) break;
	}
	cerr << endl;
	for (int i = 0; i < 10; ++ i) cout << a[i] << endl;
	cout << endl;
	for (int i = 0; i < 10; ++ i) cout << b[i] << endl;
}
