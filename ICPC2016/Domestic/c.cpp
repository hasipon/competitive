#include <bits/stdc++.h>
using namespace std;
const int MAX = 7368791;
int main() {
	for (;;) {
		int m, n;
		cin >> m >> n;
		if (!m) break;
		vector<bool> a(MAX+1);
		for (int i = m; ; ++ i) if (!a[i]) {
			if (n == 0) { cout << i << endl; break; }
			for (int j = i; j < MAX; j += i) a[j] = true;
			-- n;
		}
	}
}
