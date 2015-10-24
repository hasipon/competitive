#include <bits/stdc++.h>
using namespace std;
int N;
char buf[300][300];
vector<int> f() {
	vector<int> r(N);
	for (int i = 0; i < N; ++ i) r[i] = i + 1;
	return r;
}
int main() {
	for (;;) {
		scanf("%d", &N);
		if (!N) break;
		for (int i = 0; i < N-1; ++ i) {
			for (int j = 0; j <= i; ++ j) {
				putchar((i+j)%2 ? '@' : 'o');
			}
			puts("");
		}
		for (int j = 0; j < N; ++ j) putchar('#');
		puts("");
		fflush(stdout);
		for (int i = 0; i < N; ++ i) scanf("%s", buf[i]);
		auto r = f();
		for (int i = 0; i < N; ++ i) {
			if (i) putchar(' ');
			printf("%d", r[i]);
		}
		puts("");
		fflush(stdout);
	}
}
