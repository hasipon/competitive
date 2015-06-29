#include <bits/stdc++.h>
using namespace std;
struct TheFootballDivTwo {
	int find(int yourScore, vector <int> s, vector <int> t) {
		int x = 0, y = 0, z = 0, n = 1;
		for (int i = 0; i < s.size(); ++ i) {
			n += t[i];
			if (yourScore >= s[i]) {
				x += t[i];
			} else if (yourScore >= s[i] - 3) {
				y += t[i];
			} else if (yourScore < s[i] - 6) {
				x += t[i];
				z += t[i];
			}
		}
		n -= 2 + 2*x + y;
		if (n > 0) z += (n + 1) / 2;
		return 1 + z;
	}
};
