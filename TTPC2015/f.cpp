#include <bits/stdc++.h>
using namespace std;
string A;
bool visited[101][2];
int memo[101][2];
int f(int p, int q) {
	if (p < 0) {
		return 0;
	}
	if (visited[p][q]) return memo[p][q];
	visited[p][q] = true;
	if (A[p] == '0') {
		if (q) {
			return memo[p][q] = max(f(p-1, 0), f(p-1, 1));
		} else {
			return memo[p][q] = f(p-1, 0) + 1;
		}
	} else if (A[p] == '9') {
		if (q) {
			return memo[p][q] = f(p-1, 1) + 1;
		} else {
			return memo[p][q] = max(f(p-1, 0), f(p-1, 1));
		}
	} else {
		return memo[p][q] = max(f(p-1, 0), f(p-1, 1));
	}
}
int main() {
	cin >> A;
	cout << f(A.length()-1, 0) << endl;
}
