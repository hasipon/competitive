#include <bits/stdc++.h>
using namespace std;
struct UnionFind {
	vector<int> data;
	UnionFind(int n) : data(n, -1) {}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	bool merge(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) return false;
		if (data[y] < data[x]) swap(x, y);
		data[x] += data[y];
		data[y] = x;
		return true;
	}
};
struct ChristmasTreeDecoration {
	int solve(vector <int> col, vector <int> x, vector <int> y) {
		for (int& t : x) -- t;
		for (int& t : y) -- t;
		int N = col.size();
		vector<pair<int,int>> a;
		for (int i = 0; i < x.size(); ++ i) {
			a.push_back(make_pair(col[x[i]] == col[y[i]] ? 1 : 0, i));
		}
		sort(a.begin(), a.end());
		UnionFind uf(N);
		int r = 0;
		for (auto e : a) {
			if (uf.merge(x[e.second], y[e.second])) r += e.first;
		}
		return r;
	}
};
