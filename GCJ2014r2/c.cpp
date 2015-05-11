#include <bits/stdc++.h>
using namespace std;

struct edge { int to, cap, rev; };

struct Solver {
	int W, H, B;
	vector<int> X0, Y0, X1, Y1;
	Solver() {
		cin >> W >> H >> B;
		X0 = vector<int>(B);
		Y0 = vector<int>(B);
		X1 = vector<int>(B);
		Y1 = vector<int>(B);
		for (int i = 0; i < B; ++ i) cin >> X0[i] >> Y0[i] >> X1[i] >> Y1[i];
	}
	vector<vector<bool>> a;
	int V;
	vector<vector<edge>> G;
	vector<bool> used;
	void add_edge(int from, int to) {
		G[from].push_back((edge){to, 1, (int)G[to].size()});
		G[to].push_back((edge){from, 0, (int)G[from].size()-1});
	}
	int dfs(int v, int t, int f) {
		if (v == t) return f;
		used[v] = true;
		for (int i = 0; i < (int)G[v].size(); ++ i) {
			auto& e = G[v][i];
			if (!used[e.to] && e.cap > 0) {
				int d = dfs(e.to, t, min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}
	int max_flow(int s, int t) {
		int flow = 0;
		for (;;) {
			used = vector<bool>(V);
			int f = dfs(s, t, 1);
			if (f == 0) return flow;
			flow += f;
		}
	}
	int f() {
		a = vector<vector<bool>>(H, vector<bool>(W, true));
		for (int i = 0; i < B; ++ i) {
			for (int y = Y0[i]; y <= Y1[i]; ++ y) {
				for (int x = X0[i]; x <= X1[i]; ++ x) {
					a[y][x] = false;
				}
			}
		}
		V = H*W*2 + 2;
		G = vector<vector<edge>>(V);
		for (int i = 0; i < H; ++ i) {
			for (int j = 0; j < W; ++ j) {
				add_edge((i*W+j)*2 + 2, (i*W+j)*2 + 3);
			}
		}
		for (int i = 1; i < H; ++ i) {
			for (int j = 0; j < W; ++ j) if (a[i-1][j] && a[i][j]) {
				add_edge(((i-1)*W+j)*2 + 3, (i*W+j)*2 + 2);
				add_edge((i*W+j)*2 + 3, ((i-1)*W+j)*2 + 2);
			}
		}
		for (int i = 0; i < H; ++ i) {
			for (int j = 1; j < W; ++ j) if (a[i][j-1] && a[i][j]) {
				add_edge((i*W+(j-1))*2 + 3, (i*W+j)*2 + 2);
				add_edge((i*W+j)*2 + 3, (i*W+(j-1))*2 + 2);
			}
		}
		for (int i = 0; i < W; ++ i) {
			add_edge(0, i*2 + 2);
			add_edge(((H-1)*W+i)*2 + 3, 1);
		}
		return max_flow(0, 1);
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
