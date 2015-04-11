#include <bits/stdc++.h>
using namespace std;

struct Solver {
	int N;
	vector<int> A;
	Solver() {
		cin >> N;
		A = vector<int>(N);
		for (int i = 0; i < N; ++ i) cin >> A[i];
	}
	map<int,int> pos;
	int g(const vector<int>& a) {
		vector<int> b(N);
		for (int i = 0; i < (int)a.size(); ++ i) {
			b[i] = pos[a[i]];
		}
		int r = 0;
		for (int i = 0; i < N; ++ i) {
			for (int j = 1; j < N; ++ j) {
				if (b[j-1] > b[j]) {
					swap(b[j-1], b[j]);
					++ r;
				}
			}
		}
		return r;
	}
	bool h(const vector<int>& a) {
		bool flag = false;
		for (unsigned i = 1; i < a.size(); ++ i) {
			if (a[i-1] > a[i]) {
				flag = true;
			} else {
				if (flag) return false;
			}
		}
		return true;
	}
	int f() {
		int r = 1<<30;
		for (int i = 0; i < (int)A.size(); ++ i) {
			pos[A[i]] = i;
		}
		vector<int> a = A;
		sort(a.begin(), a.end());
		do {
			if (h(a)) r = min(r, g(a));
		} while (next_permutation(a.begin(), a.end()));
		return r;
	}
	int ans;
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
