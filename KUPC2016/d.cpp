#include <bits/stdc++.h>
using namespace std;
void output(const vector<int>& a) {
	for (int c : a) {
		cout << ((c&1)?"#":".");
	}
	cout << endl;
	for (int c : a) {
		cout << ((c&2)?"#":".");
	}
	cout << endl;
}
int main() {
	int N;
	cin >> N;
	int mode = 0;
	vector<int> a;
	for (;;) {
		if (!mode) {
			a.push_back(0);
		} else {
			a.insert(a.begin(), 0);
		}
		for (int i = 0; i < 4; ++ i) {
			a[mode ? 0 : a.size()-1] = i;
			output(a);
			string s;
			cin >> s;
			if (s == "end") return 0;
			if (s == "T") goto next;
		}
		if (mode) throw 1;
		a.pop_back();
		mode = 1;
		next:;
	}
}
