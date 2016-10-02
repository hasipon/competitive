#include <bits/stdc++.h>
using namespace std;
int main() {
	int N, A, B;
	cin >> N >> A >> B;
	int r = 0;
	for (int i = 0; i < N; ++ i) {
		int x;
		cin >> x;
		if (!(A <= x && x < B)) ++ r;
	}
	cout << r << endl;
}
