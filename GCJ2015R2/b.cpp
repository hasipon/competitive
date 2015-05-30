#include <bits/stdc++.h>
using namespace std;

struct Solver {
	int N;
	double V, X;
	vector<double> R, C;
	Solver() {
		cin >> N >> V >> X;
		R.resize(N);
		C.resize(N);
		for (int i = 0; i < N; ++ i) cin >> R[i] >> C[i];
	}
	double rr;
	void run() {
		rr = -1;
		if (N == 1) {
			if (C[0] == X) {
				rr = V / R[0];
			}
		} else {
			if (C[0] == X && C[1] == X) {
				rr = V / (R[0] + R[1]);
			} else if (C[0] == X) {
				rr = V / R[0];
			} else if (C[1] == X) {
				rr = V / R[1];
			} else if ((C[0] < X && X < C[1]) || (C[1] < X && X < C[0])) {
				double x = (X - C[1]) / (C[0] - C[1]);
				if (R[1] / R[0] <= (1-x) / x) {
					rr = V / (R[1] / (1 - x));
				} else {
					rr = V / (R[0] / x);
				}
			}
		}
	}
	int tt_;
	void output() {
		cout << "Case #" << tt_ << ": ";
		if (rr < 0) {
			cout << "IMPOSSIBLE";
		} else {
			printf("%.9f", rr);
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
