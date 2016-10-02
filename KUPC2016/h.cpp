#include <bits/stdc++.h>
using namespace std;
int N;
vector<long long> A, B;
vector<int> AA, BB;
map<int,map<int,int>> memo;
int f(int p, int q) {
	if (p == BB.size()) return 0;
	if (memo[p].count(q)) return memo[p][q];
	int r = 1<<30;
	for (int j = q; j < AA.size(); ++ j) {
		r = min(r, abs(BB[p] - AA[j]) + f(p+1, j+1));
	}
	return memo[p][q] = r;
}
int main() {
	cin >> N;
	if (N > 100) throw 1;
	A.resize(N);
	B.resize(N);
	for (auto& x : A) cin >> x;
	for (auto& x : B) cin >> x;
	long long sumA = 0;
	for (auto x : A) sumA += x;
	if (sumA > 400) throw 1;
	for (int i = 0; i < N; ++ i) for (int j = 0; j < A[i]; ++ j) AA.push_back(i);
	for (int i = 0; i < N; ++ i) for (int j = 0; j < B[i]; ++ j) BB.push_back(i);
	cout << f(0,0) << endl;
}
