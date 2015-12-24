#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
	cin >> N;
	vector<long long> a(N);
	for (auto& x : a) cin >> x;
	long long ans = 0;
	for (int i = 1; i < N; ++ i) ans += abs(a[i]-a[i-1]);
	cout << ans << endl;
}
