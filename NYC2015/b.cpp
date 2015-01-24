#include <bits/stdc++.h>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	for (int& x : a) cin >> x;
	sort(a.begin(), a.end());
	int s = 0, r = 0;
	for (int x : a) {
		if (x > s) {
			s += x;
			++ r;
		}
	}
	cout << r << endl;
}
