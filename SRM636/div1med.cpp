#include <bits/stdc++.h>
using namespace std;
struct ClosestRabbit {
	vector<int> x, y;
	bool f(int i, int j, int k) {
		int dxj = x[i] - x[j];
		int dyj = y[i] - y[j];
		int dj = dxj * dxj + dyj * dyj;
		int dxk = x[i] - x[k];
		int dyk = y[i] - y[k];
		int dk = dxk * dxk + dyk * dyk;
		return (dk < dj) || (dk == dj && k < j);
	}
	double getExpected(vector <string> board, int r) {
		for (int i = 0; i < board.size(); ++ i) for (int j = 0; j < board[i].size(); ++ j) if (board[i][j] == '.') {
			x.push_back(i);
			y.push_back(j);
		}
		int n = x.size();
		vector<vector<double>> C(n+1, vector<double>(n+1));
		for (int i = 0; i <= n; i++) {
			C[i][0] = C[i][i] = 1;
			for (int j = 1; j < i; j++) {
				C[i][j] = C[i-1][j] + C[i-1][j-1];
			}
		}
		double res = 0;
		for (int i = 0; i < n; ++ i) for (int j = i+1; j < n; ++ j) {
			int b = 0;
			for (int k = 0; k < n; ++ k) if (k != i && k != j) {
				if (f(i, j, k) || f(j, i, k)) ++ b;
			}
			res += C[n - 2  - b][r - 2] / C[n][r];
		}
		return res;
	}
};
