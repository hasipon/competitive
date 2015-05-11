#include <bits/stdc++.h>
using namespace std;

struct Solver {
	int M, N;
	vector<string> S;
	Solver() {
		cin >> M >> N;
		S = vector<string>(M);
		for (int i = 0; i < M; ++ i) cin >> S[i];
	}
	int g(const vector<string>& a) {
		set<string> s;
		for (auto& x : a) {
			for (int i = 1; i <= (int)x.length(); ++ i) {
				s.insert(x.substr(0, i));
			}
		}
		return s.size() + 1;
	}
	int f(const vector<vector<string>>& a) {
		for (auto& x : a) {
			if (x.empty()) return -1;
		}
		int r = 0;
		for (auto& x : a) r += g(x);
		return r;
	}
	int X, Y;
	void run() {
		X = -1;
		Y = 0;
		vector<int> a(M);
		for (;;) {
			vector<vector<string>> b(N);
			for (int i = 0; i < M; ++ i) {
				b[a[i]].push_back(S[i]);
			}
			int n = f(b);
			if (n > X) {
				X = n;
				Y = 1;
			} else if (n == X) {
				++ Y;
			}
			for (int i = 0; ; ++ i) {
				if (i == M) return;
				if (++ a[i] == N) {
					a[i] = 0;
				} else break;
			}
		}
	}
	int tt_;
	void output() {
		cout << "Case #" << tt_ << ": ";
		cout << X << " " << Y;
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
