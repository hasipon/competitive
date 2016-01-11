#include <bits/stdc++.h>
using namespace std;

struct Solver {
	int N;
	vector<long> X, Y;
	Solver() {
		cin >> N;
		X.resize(N);
		Y.resize(N);
		for (int i = 0; i < N; ++ i) cin >> X[i] >> Y[i];
	}
	int ans;
	void run() {
		vector<map<long, int>> cnt(N);
		for (int i = 0; i < N; ++ i) for (int j = i+1; j < N; ++ j) {
			long x = X[i] - X[j];
			long y = Y[i] - Y[j];
			++ cnt[i][x*x + y*y];
			++ cnt[j][x*x + y*y];
		}
		ans = 0;
		for (int i = 0; i < N; ++ i) for (auto p : cnt[i]) {
			int x = p.second;
			ans += x * (x - 1) / 2;
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
