#include <bits/stdc++.h>
using namespace std;

struct Solver {
	int N, X;
	vector<int> S;
	Solver() {
		cin >> N >> X;
		S = vector<int>(N);
		for (int i = 0; i < N; ++ i) cin >> S[i];
	}
	int ans;
	int f() {
		sort(S.begin(), S.end());
		int r = 0;
		while (!S.empty()) {
			if (S.size() >= 2 && S[0] + S.back() <= X) {
				S.pop_back();
				S.erase(S.begin());
			} else {
				S.pop_back();
			}
			++ r;
		}
		return r;
	}
	void run() {
		ans = f();
	}
	int tt_;
	void output() {
		cout << "Case #" << tt_ << ": ";
		cout << ans;
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
