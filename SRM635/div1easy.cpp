#include <bits/stdc++.h>
using namespace std;
struct SimilarRatingGraph {
	double maxLength(vector <int> date, vector <int> rating) {
		int n = date.size() - 1;
		vector<long long> dx(n), dy(n);
		for (int i = 1; i < date.size(); ++ i) {
			dx[i-1] = date[i] - date[i-1];
			dy[i-1] = rating[i] - rating[i-1];
		}
		double r = 0;
		for (int i = 0; i < n; ++ i) for (int j = 0; j < n; ++ j) if (i != j) {
			if (dy[i] * dx[j] == dy[j] * dx[i]) { // dy[i] / dx[i] == dy[j] / dx[j]
				double rr = hypot(dx[i], dy[i]);
				for (int k = 1; i + k < n && j + k < n; ++ k) {
					if (dx[j+k] * dx[i] != dx[i+k] * dx[j]) break; // dx[j+k] / dx[j] != dx[i+k] / dx[i]
					if (dy[j+k] * dx[i] != dy[i+k] * dx[j]) break; // dy[j+k] / dx[j] != dy[i+k] / dx[i]
					rr += hypot(dx[i+k], dy[i+k]);
				}
				r = max(r, rr);
			}
		}
		return r;
	}
};
