#include <iostream>
#include <vector>
using namespace std;
int main() {
	int N, m;
	cin >> N >> m;
	vector<bool> b(N);
	for (int i = 0; i < m; ++ i) {
		int c, d;
		cin >> c >> d;
		-- c; -- d;
		for (int j = c; j < d; ++ j) {
			b[j] = true;
		}
	}
	int r = N+1;
	for (int i = 0; i < N; ++ i) if (b[i]) r += 2;
	cout << r << endl;
}
