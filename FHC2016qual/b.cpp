#include <bits/stdc++.h>
using namespace std;

struct Solver {
	int N;
	vector<string> G;
	Solver() {
		G.resize(2);
		cin >> N >> G[0] >> G[1];
		G[0] = "X" + G[0] + "X";
		G[1] = "X" + G[1] + "X";
	}
	int ans;
	void run() {
		ans = 0;
		for (int i = 1; i <= N; ++ i) {
			for (int k = 0; k < 2; ++ k) {
				if (G[k][i-1] == 'X' && G[k][i] == '.' && G[k][i+1] == 'X' && G[k^1][i] == '.') {
					G[k][i] = '*';
					G[k^1][i] = '*';
					for (int j = i+1; G[k^1][j] == '.'; ++ j) G[k^1][j] = '*';
					for (int j = i-1; G[k^1][j] == '.'; -- j) G[k^1][j] = '*';
					++ ans;
				}
			}
		}
		for (int i = 1; i <= N; ++ i) {
			for (int k = 0; k < 2; ++ k) {
				if (G[k][i] == '.' && G[k][i-1] != '.') ++ ans;
			}
		}
	}
	int tt_;
	void output() {
		cout << "Case #" << tt_ << ": ";
		cout << ans << endl;
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
