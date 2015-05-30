#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
struct Solver {
	int R, C;
	vector<string> A;
	Solver() {
		cin >> R >> C;
		A.resize(R);
		for (int i = 0; i < R; ++ i) cin >> A[i];
	}
	bool f(int y, int x, char d) {
		int dy, dx;
		if (d == '<') { dy = 0; dx = -1; }
		else if (d == '>') { dy = 0; dx = 1; }
		else if (d == '^') { dy = -1; dx = 0; }
		else if (d == 'v') { dy = 1; dx = 0; }
		else throw 1;
		y += dy;
		x += dx;
		while (0 <= y && y < R && 0 <= x && x < C) {
			if (A[y][x] != '.') return true;
			y += dy;
			x += dx;
		}
		return false;
	}
	int r;
	void run() {
		r = 0;
		for (int i = 0; i < R; ++ i) for (int j = 0; j < C; ++ j) if (A[i][j] != '.') {
			if (f(i, j, A[i][j])) continue;
			for (int k = 0; k < 4; ++ k) {
				if (f(i, j, "^v<>"[k])) {
					++ r;
					goto next;
				}
			}
			r = INF;
			return;
			next:;
		}
	}
	int tt_;
	void output() {
		cout << "Case #" << tt_ << ": ";
		if (r == INF) {
			cout << "IMPOSSIBLE";
		} else {
			cout << r;
		}
		cout << endl;
	}
};

int main() {
	int T;
	cin >> T;
	vector<future<Solver*>> results;
	for (int tt = 1; tt <= T; ++ tt) {
		auto a = new Solver;
		a->tt_ = tt;
		results.push_back(async(
			launch::async, // async or deferred
			[](Solver* solver) {
				solver->run();
				return solver;
			},
			a
		));
	}
	for (auto& x : results) {
		auto a = x.get();
		a->output();
		delete a;
	}
}
