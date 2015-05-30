#include <bits/stdc++.h>
using namespace std;

struct Solver {
	int N;
	vector<vector<string>> A;
	Solver() {
		cin >> N;
		A.resize(N);
		string buf;
		getline(cin, buf);
		for (int i = 0; i < N; ++ i) {
			getline(cin, buf);
			istringstream in(buf);
			string s;
			while (in >> s) A[i].push_back(s);
		}
	}
	int r;
	void run() {
		map<string, int> a;
		for (int i = 0; i < N; ++ i) {
			for (string s : A[i]) a[s] |= 1 << i;
		}
		vector<int> b(1<<N);
		for (auto x : a) {
			int t = x.second;
			for (int i = 0; i < (1<<N); ++ i) {
				if ((t & i) && (t & ~i)) ++ b[i];
			}
		}
		r = 1<<30;
		for (int i = 1; i < (1<<N); i += 4) {
			r = min(r, b[i]);
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
