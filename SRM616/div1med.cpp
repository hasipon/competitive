#include <bits/stdc++.h>
using namespace std;
struct ColorfulCoins {
	vector<long long> a;
	int pow(int x, int y) {
		int r = 1;
		for (int i = 0; i < y; ++ i) r *= x;
		return r;
	}
	bool f(int m) {
		int b = 1;
		int c = 1;
		for (int i = 0; i < a.size(); ++ i) {
			if (-- c == 0) {
				++ b;
				c = pow(b, m) - pow(b-1, m);
			}
			if (a[i] < b) return false;
		}
		return true;
	}
	int minQueries(vector<long long> values) {
		for (int i = 1; i < values.size(); ++ i) {
			a.push_back(values[i] / values[i-1]);
		}
		sort(a.begin(), a.end());
		for (int i = 1; ; ++ i) if (f(i)) return i;
	}
};
