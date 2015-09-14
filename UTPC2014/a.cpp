#include <bits/stdc++.h>
using namespace std;
int main() {
	vector<string> a;
	string s;
	while (cin >> s) a.push_back(s);
	for (;;) {
		for (int i = 0; i+2 < a.size(); ++ i) {
			if (a[i] == "not" && a[i+1] == "not" && a[i+2] != "not") {
				a.erase(a.begin() + i, a.begin() + i + 2);
				goto next;
			}
		}
		break;
		next:;
	}
	for (int i = 0; i < a.size(); ++ i) {
		if (i) cout << " ";
		cout << a[i];
	}
	cout << endl;
}
