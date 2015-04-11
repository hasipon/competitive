#include <bits/stdc++.h>
using namespace std;

struct Solver {
	Solver() {
	}
	void run() {
	}
	int tt_;
	void output() {
		cout << "Case #" << tt_ << ": ";
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
