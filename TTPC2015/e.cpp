#include <bits/stdc++.h>
using namespace std;
int main() {
	int N, K;
	cin >> N >> K;
	vector<vector<int>> a(N, vector<int>(N));
	set<int> xx, yy;
	for (int i = 0; i < N; ++ i) for (int j = 0; j < N; ++ j) a[i][j] = ((i+j)&1)*2-1;
	for (int i = 0; i < K; ++ i) {
		int y, x;
		cin >> y >> x;
		a[y-1][x-1] *= -1;
		for (int d = -1; d <= +1; ++ d) {
			if (0<=x+d && x+d <= N) xx.insert(x+d);
			if (0<=y+d && y+d <= N) yy.insert(y+d);
		}
	}
	xx.insert(0);
	yy.insert(0);
	xx.insert(1);
	yy.insert(1);
	xx.insert(N-1);
	yy.insert(N-1);
	xx.insert(N);
	yy.insert(N);
	vector<vector<int>> b(N+1, vector<int>(N+1));
	for (int i = 1; i <= N; ++ i) {
		for (int j = 1; j <= N; ++ j) {
			b[i][j] = b[i-1][j] + b[i][j-1] - b[i-1][j-1] + a[i-1][j-1];
		}
	}
	int r = 0;
	for (int x1 : xx)
	for (int x2 : xx) if (x1 < x2)
	for (int y1 : yy)
	for (int y2 : yy) if (y1 < y2) {
		r = max(r, abs(b[y2][x2] - b[y2][x1] - b[y1][x2] + b[y1][x1]));
	}
	cout << r << endl;
}
