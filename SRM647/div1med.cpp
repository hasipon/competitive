#include <bits/stdc++.h>
using namespace std;
struct CtuRobots {
	double maxDist(int B, vector <int> cost, vector <int> cap) {
		int n = cost.size();
		vector<pair<int,int>> a;
		for (int i = 0; i < n; ++ i) a.push_back(make_pair(cap[i], cost[i]));
		sort(a.begin(), a.end());
		vector<vector<double>> dp(n+1, vector<double>(B+1));
		for (int i = 1; i <= n; ++ i) {
			for (int j = B; j >= 0; -- j) {
				dp[i][j] = dp[i-1][j];
				if (j >= a[i-1].second) {
					dp[i][j] = max(dp[i][j], dp[i-1][j - a[i-1].second] / 3 + a[i-1].first);
				}
			}
		}
		return dp[n][B] / 2;
	}
};
