#include <bits/stdc++.h>
using namespace std;
struct BoardFolding {
	set<int> g(const vector<vector<bool> >& a) {
		set<int> r;
		queue<int> Q;
		Q.push(0);
		r.insert(0);
		while (!Q.empty()) {
			int p = Q.front(); Q.pop();
			for (int i = 1; p + 2*i-1 < a.size(); ++ i) {
				for (int j = 0; j < i; ++ j) {
					if (a[p + j] != a[p + 2*i-1 - j]) goto next;
				}
				if (r.insert(p + i).second) Q.push(p + i);
				next:;
			}
		}
		return r;
	}
	int f(vector<vector<bool>> a) {
		set<int> a1 = g(a);
		reverse(a.begin(), a.end());
		set<int> a2 = g(a);
		int r = 0;
		for (int x : a1) for (int y : a2) {
			if (x < a.size() - y) ++ r;
		}
		return r;
	}
	int howMany(int N, int M, vector <string> compressedPaper) {
		vector<vector<bool> > a(N, vector<bool>(M));
		vector<vector<bool> > b(M, vector<bool>(N));
		int tonumber[128] = {};
		for (int i = 0; i < 10; ++ i) tonumber[i + '0'] = i;
		for (int i = 0; i < 26; ++ i) tonumber[i + 'a'] = i + 10;
		for (int i = 0; i < 26; ++ i) tonumber[i + 'A'] = i + 36;
		tonumber['#'] = 62;
		tonumber['@'] = 63;
		for (int i = 0; i < N; ++ i) for (int j = 0; j < M; ++ j) {
			a[i][j] = b[j][i] = (tonumber[(int)compressedPaper[i][j / 6]] >> (j % 6)) % 2;
		}
		return f(a) * f(b);
	}
};