#include <bits/stdc++.h>
using namespace std;
struct ConundrumReloaded {
	int f(string s) {
		int res = 1<<30;
		for (int k = 0; k < 2; ++ k) {
			int h = k, cnt = k;
			for (int i = 0; i < s.length(); ++ i) {
				int j = h ^ (s[i] == 'L');
				h = j;
				cnt += j;
			}
			res = min(res, cnt);
		}
		return res;
	}
	int minimumLiars(string answers) {
		int res = 1<<30;
		if (answers.find('?') == string::npos) {
			for (int k = 0; k < 2; ++ k) {
				int h = k, cnt = 0;
				for (int i = 0; i < answers.length(); ++ i) {
					int j = h ^ (answers[i] == 'L');
					h = j;
					cnt += j;
				}
				if (h == k) res = min(res, cnt);
			}
		} else if (answers.find('L') == string::npos && answers.find('H') == string::npos) {
			return 0;
		} else {
			while (answers[0] == '?' || answers[answers.length()-1] != '?') answers = answers.substr(1) + answers[0];
			int s = 0;
			res = 0;
			for (int i = 0; i < answers.length(); ++ i) {
				if (answers[i] == '?') {
					if (s >= 0) {
						res += f(answers.substr(s, i - s));
						s = -1;
					}
				} else if (s < 0) {
					s = i;
				}
			}
		}
		if (res == 1<<30) return -1;
		return res;
	}
};
