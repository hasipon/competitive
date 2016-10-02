#include <bits/stdc++.h>
using namespace std;
struct Hoge {
	int mode;
	bool maxfunc;
	Hoge* left;
	Hoge* right;
	string num;
	Hoge() : mode(0) {}
	bool read(char c) {
		switch (mode) {
			case 0:
				if (c == '^') {
					mode = 100;
					maxfunc = true;
					left = new Hoge;
					right = new Hoge;
				} else if (c == '_') {
					mode = 100;
					maxfunc = false;
					left = new Hoge;
					right = new Hoge;
				} else {
					mode = 1;
					num += c;
					if (c == '0') mode = 2;
				}
				return true;
			case 1:
				if (c == '?') {
					mode = 2;
					return true;
				}
				if ('0' <= c && c <= '9') {
					num += c;
					mode = 2;
					return true;
				} else {
					mode = 2;
				}
				return false;
			case 2:
				return false;
			case 100:
				if (c != '(') throw 1;
				mode = 101;
				return true;
			case 101:
				if (left->read(c)) return true;
				if (c == ',') { mode = 102; return true; }
				throw 1;
			case 102:
				if (right->read(c)) return true;
				if (c == ')') { mode = 103; return true; }
				throw 1;
			case 103:
				return false;
		}
	}
	int ma() {
		switch (mode) {
			case 0: return 99;
			case 1: return (num[0]-'0') * 10 + 9;
			case 2:
				if (num.length() == 1) return num[0]-'0';
				else return (num[0]-'0') * 10 + (num[1]-'0');
			case 100: return 99;
			case 101:
			case 102:
			case 103:
				if (maxfunc) return max(left->ma(), right->ma());
				else return min(left->ma(), right->ma());
		}
		throw 1;
	}
	int mi() {
		switch (mode) {
			case 0: return 0;
			case 1: return num[0]-'0';
			case 2:
				if (num.length() == 1) return num[0]-'0';
				else return (num[0]-'0') * 10 + (num[1]-'0');
			case 100: return 0;
			case 101:
			case 102:
			case 103:
				if (maxfunc) return max(left->mi(), right->mi());
				else return min(left->mi(), right->mi());
		}
		throw 1;
	}
};
int main() {
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++ i) {
		Hoge hoge;
		string s;
		cin >> s;
		for (int i = 0; i < s.length(); ++ i) {
			hoge.read(s[i]);
			int ma = hoge.ma(), mi = hoge.mi();
			//cout << i+1 << " " << mi << " " << ma << endl;
			if (ma == mi) {
				cout << ma << " " << i+1 << endl;
				break;
			}
		}
	}
}
