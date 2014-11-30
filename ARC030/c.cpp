#include <bits/stdc++.h>
using namespace std;

struct StronglyConnectedComponents {
	vector<vector<int>> g;
	vector<int> num, low;
	stack<int> S;
	vector<bool> inS;
	int time;
	vector<vector<int>> scc;
	StronglyConnectedComponents(vector<vector<int>> g)
		: g(g), num(g.size()), low(g.size()), inS(g.size()), time(0)
	{
		for (int i = 0; i < (int)g.size(); ++ i) if (num[i] == 0) {
			visit(i);
		}
	}
	void visit(int v) {
		low[v] = num[v] = ++time;
		S.push(v); inS[v] = true;
		for (int w : g[v]) {
			if (num[w] == 0) {
				visit(w);
				low[v] = min(low[v], low[w]);
			} else if (inS[w])
				low[v] = min(low[v], num[w]);
		}
		if (low[v] == num[v]) {
			scc.push_back(vector<int>());
			while (1) {
				int w = S.top(); S.pop(); inS[w] = false;
				scc.back().push_back(w);
				if (v == w) break;
			}
		}
	}
};

int n, m, k, L;
vector<string> c;
vector<vector<int>> G, g;
vector<string> V;
vector<vector<string>> memo;

string f(int p, int q) {
	if (memo[p][q] != "") return memo[p][q];
	string r = "~";
	if (q <= V[p].length()) r = V[p].substr(0, q);
	for (int i = 0; i <= V[p].length(); ++ i) {
		if (q-i <= 0) break;
		for (int x : g[p]) {
			string rr = f(x, q-i);
			if (rr != "~") {
				r = min(r, V[p].substr(0, i) + rr);
			}
		}
	}
	return memo[p][q] = r;
}

int main() {
	cin >> n >> m >> k;
	c.resize(n);
	for (int i = 0; i < n; ++ i) cin >> c[i];
	G.resize(n);
	for (int i = 0; i < m; ++ i) {
		int a, b;
		cin >> a >> b;
		-- a; -- b;
		G[a].push_back(b);
	}
	StronglyConnectedComponents scc(G);
	L = scc.scc.size();
	vector<int> s(n);
	for (int i = 0; i < L; ++ i) {
		for (int x : scc.scc[i]) s[x] = i;
	}
	g.resize(L);
	V.resize(L);
	for (int i = 0; i < L; ++ i) {
		set<int> ss;
		for (int y : scc.scc[i]) {
			V[i] += c[y];
			for (int x : G[y]) if (s[x] != i) ss.insert(s[x]);
		}
		sort(V[i].begin(), V[i].end());
		for (int x : ss) g[i].push_back(x);
	}
	/*for (int i = 0; i < L; ++ i) {
		cout << V[i] << " ";
		for (int x : g[i]) cout << x << " "; cout << endl;
	}*/
	memo = vector<vector<string>>(L, vector<string>(k+1));
	string r = "~";
	for (int i = 0; i < L; ++ i) {
		string rr = f(i, k);
		r = min(r, rr);
	}
	if (r == "~") {
		cout << -1 << endl;
	} else {
		cout << r << endl;
	}
}
