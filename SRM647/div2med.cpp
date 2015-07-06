#include <bits/stdc++.h>
using namespace std;
struct TravellingSalesmanEasy {
	int getMaxProfit(int M, vector <int> profit, vector <int> city, vector <int> visit) {
		vector<vector<int>> a(M);
		for (int i = 0; i < profit.size(); ++ i) {
			a[city[i]-1].push_back(profit[i]);
		}
		for (auto& b : a) sort(b.begin(), b.end());
		int r = 0;
		for (int x : visit) if (a[x-1].size()) {
			r += a[x-1].back();
			a[x-1].pop_back();
		}
		return r;
	}
};
