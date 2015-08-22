#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<long long> A;
long long memo[5001][5001];
bool visited[5001][5001];
long long f(int p, int q, int x) {
	if (p == 0) return 0;
	if (visited[p][q]) return memo[p][q];
	visited[p][q] = true;
	long long r = 1LL<<60;
	if (q < p) r = min(r, f(p-1, q, x + n/k) + A[x+n/k-1] - A[x]);
	if (q > 0) r = min(r, f(p-1, q-1, x + n/k + 1) + A[x+n/k] - A[x]);
	return memo[p][q] = r;
}
int main() {
	cin >> n >> k;
	A.resize(n);
	for (int i = 0; i < n; ++ i) cin >> A[i];
	sort(A.begin(), A.end());
	cout << f(k, n % k, 0) << endl;
}
