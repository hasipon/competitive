#include <bits/stdc++.h>
using namespace std;
struct TheKingsArmyDiv1 {
	int getNumber(vector <string> state) {
		int r = 0;
		vector<char> a;
		for (int i = 0; i < state[0].size(); ++ i) {
			if (state[0][i] == state[1][i]) {
				if (state[0][i] == 'S') ++ r;
			} else {
				a.push_back(state[0][i]);
			}
		}
		if (r == state[0].size()) return -1;
		if (a.size() == 0) return r;
		int c = 0;
		for (int i = 1; i < a.size(); ++ i) if (a[i] != a[i-1]) ++ c;
		return (c + 1) / 2 + 1 + r;
	}
};
