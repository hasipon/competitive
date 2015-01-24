#include <bits/stdc++.h>
using namespace std;
int main() {
	int N, M;
	cin >> N >> M;
	if (N > 200) throw 1;
	set<pair<int,int>> hoge;
	for (int i = 0; i < M; ++ i) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int k = 1; k <= c; ++ k) for (int j = k; j <= c; ++ j) {
			hoge.insert(make_pair(a + j, b + k));
		}
	}
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++ i) {
		int a, b, c;
		cin >> a >> b >> c;
		int r = 0;
		for (int k = 1; k <= c; ++ k) for (int j = k; j <= c; ++ j) {
			r += 1 - hoge.count(make_pair(a + j, b + k));
		}
		cout << r << endl;
	}
}
