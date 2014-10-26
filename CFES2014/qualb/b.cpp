#include <bits/stdc++.h>
using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	int r = 0;
	for (int i = 1; i <= N; ++ i) {
		int n;
		cin >> n;
		r += n;
		if (r >= K) {
			cout << i << endl;
			break;
		}
	}
}
