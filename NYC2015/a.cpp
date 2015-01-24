#include <bits/stdc++.h>
using namespace std;
bool f(int N) {
	vector<int> a;
	while (N) {
		a.push_back(N&1);
		N >>= 1;
	}
	vector<int> b = a;
	reverse(b.begin(), b.end());
	return b == a;
}
int main() {
	int N;
	cin >> N;
	cout << (f(N) ? "Yes" : "No") << endl;
}
