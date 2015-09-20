#include <bits/stdc++.h>
using namespace std;
int N, K;
bool f(const vector<int>& a) {
	vector<bool> b(N);
	for (int i = 0; i < N; ++ i) {
		if (a[i] == i) return false;
		b[a[i]] = true;
	}
	for (bool x : b) if (!x) return false;
	int r = 0;
	for (int i = 0; i < N; ++ i) {
		for (int j = 1, k = a[i]; ; ++ j) {
			if (k == i) {
				r = max(r, j);
				break;
			}
			k = a[k];
		}
	}
	return r == K;
}
int main() {
	cin >> N >> K;
	if (N > 8) throw 1;
	vector<int> a(N);
	for (int i = 0; i < N; ++ i) a[i] = i;
	int r = 0;
	do {
		if (f(a)) ++ r;
	} while (next_permutation(a.begin(), a.end()));
	cout << r << endl;
}
