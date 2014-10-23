#include <bits/stdc++.h>
using namespace std;

vector<int> f(vector<int> x) {
	vector<int> a(1, 1);
	for (int i = 1; i < x.size(); ++ i) {
		if (x[i-1] == x[i]) {
			++ a.back();
		} else {
			a.push_back(1);
		}
	}
	return a;
}
int func(vector<int> b, vector<int> p) {
	if (f(b) == p) return 0;

	map<vector<int>, int> dist;
	queue<vector<int> > Q;
	dist[b] = 0;
	Q.push(b);
	while (!Q.empty()) {
		vector<int> c = Q.front(); Q.pop();
		for (int i = 1; i < c.size(); ++ i) {
			vector<int> d = c;
			swap(d[i-1], d[i]);
			if (!dist.count(d)) {
				dist[d] = dist[c] + 1;
				if (f(d) == p) return dist[d];
				Q.push(d);
			}
		}
	}
}
int main() {
	int N, M;
	cin >> N >> M;
	vector<int> b(N), p(M);
	for (int i = 0; i < N; ++ i) cin >> b[i];
	for (int i = 0; i < M; ++ i) cin >> p[i];
	cout << func(b, p) << endl;
}
