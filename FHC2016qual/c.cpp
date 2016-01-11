#include <bits/stdc++.h>
using namespace std;

struct Solver {
	int N, P;
	vector<long> B;
	Solver() {
		cin >> N >> P;
		B.resize(N);
		for (auto& x : B) cin >> x;
	}
	long ans;
	void run() {
		long s = 0;
		for (int i = 0, j = 0; i < N; ++ i) {
			while (j < N && s+B[j] <= P) s += B[j++];
			ans += j - i;
			s -= B[i];
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
