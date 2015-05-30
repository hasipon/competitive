#include <bits/stdc++.h>
using namespace std;

struct Solver {
	int R, C;
	Solver() {
		cin >> R >> C;
	}
	int r;
	void run() {
		if (R == 3 || R == 6) r = 2;
		else r = 1;
		if (C == 6) {
			if (R == 2) r += 1;
			if (R == 3) r += 0;
			if (R == 4) r += 2;
			if (R == 5) r += 2;
			if (R == 6) r += 7;
		}
		if (C == 4) {
			if (R == 2) r += 0;
			if (R == 3) r += 1;
			if (R == 4) r += 0;
			if (R == 5) r += 2;
			if (R == 6) r += 2;
		}
		if (C == 3 || C == 6) {
			if (R == 2) r += 1;
			if (R == 3) r += 0;
			if (R == 4) r += 2;
			if (R == 5) r += 2;
			if (R == 6) r += 4;
		}
		if (C == 6) {
			if (R == 6) r += 6;
		}
	}
	int tt_;
	void output() {
		cout << "Case #" << tt_ << ": ";
		cout << r << endl;
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
