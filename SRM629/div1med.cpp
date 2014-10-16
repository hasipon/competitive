#include <bits/stdc++.h>
using namespace std;
struct CandyCollection {
	vector<pair<int,int>> b;
	vector<vector<int>> memo;
	int f(int p, int q) {
		if (p == b.size()) return q ? 0 : (1<<29);
		if (memo[p][q] >= 0) return memo[p][q];
		if (q & 1) {
			return memo[p][q] = min(
				b[p].first + 1 + f(p+1, q|1),
				f(p+1, q&~1)
			);
		} else {
			return memo[p][q] = min(
				max(b[p].first, b[p].second) + 1 + f(p+1, q|1),
				b[p].second + 1 + f(p+1, q&~1)
			);
		}
	}
	int solve(vector <int> Type1, vector <int> Number1, vector <int> Type2, vector <int> Number2) {
		int N = Type1.size();
		vector<vector<int>> a(N);
		for (int i = 0; i < N; ++ i) {
			a[Type1[i]].push_back(i);
			a[Type2[i]].push_back(i);
		}
		vector<bool> visited(N);
		int r = 0;
		for (int i = 0; i < N; ++ i) if (!visited[i]) {
			b = vector<pair<int,int>>();
			for (int j = i, k = Type1[i]; !visited[j]; ) {
				visited[j] = true;
				if (Type1[j] == k) {
					b.push_back(make_pair(Number1[j], Number2[j]));
					k = Type2[j];
				} else {
					b.push_back(make_pair(Number2[j], Number1[j]));
					k = Type1[j];
				}
				if (a[k][0] != j) j = a[k][0];
				else j = a[k][1];
			}
			memo = vector<vector<int>>(b.size(), vector<int>(4, -1));
			r += min(min(min(
				f(1, 0),
				b[0].first + 1 + f(1, 1) ),
				b[0].second + 1 + f(1, 2) ),
				max(b[0].first, b[0].second) + 1 + f(1, 3) );
		}
		return r;
	}
};
