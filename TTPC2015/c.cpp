#include <bits/stdc++.h>
using namespace std;
string S;
int find_good() {
	int r = -1, cnt = 0;
	auto p = S.find("oookayama");
	if (p == string::npos) return -1;
	while (p > 0 && S[p-1] == 'o') { -- p; ++ cnt; }
	return p;
}
void replace(int p) {
	string r1 = S.substr(0, p);
	string r2;
	while(S[p] == 'o') r2 += S[p++];
	for (;;) {
		auto p = r2.find("oo");
		if (p == string::npos) break;
		r2.replace(p, 2, "O");
		auto q = r2.find("OO");
		if (q == string::npos) continue;
		r2.replace(q, 2, "o");
	}
	string r3 = S.substr(p);
	S = r1 + r2 + r3;
}
int main() {
	cin >> S;
	for (;;) {
		int p = find_good();
		if (p < 0) break;
		replace(p);
	}
	cout << S << endl;
}
