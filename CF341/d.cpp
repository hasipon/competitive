#include <bits/stdc++.h>
using namespace std;
long double NN = -1e+300;
long double EPS = 1e-12;
long double f1(long double x, long double y, long double z) {
	if (x <= 1.0) return NN;
	return logl(logl(x)) + logl(y) * z;
}
long double f2(long double x, long double y, long double z) {
	if (x <= 1.0) return NN;
	return logl(logl(x) * y * z);
}
long double f(long double x, long double y, long double z, int t) {
	switch (t) {
	case 0: return f1(x,y,z);
	case 1: return f1(x,z,y);
	case 2: return f2(x,y,z);
	case 3: return f2(x,z,y);
	case 4: return f1(y,x,z);
	case 5: return f1(y,z,x);
	case 6: return f2(y,x,z);
	case 7: return f2(y,z,x);
	case 8: return f1(z,x,y);
	case 9: return f1(z,y,x);
	case 10: return f2(z,x,y);
	case 11: return f2(z,y,x);
	case 12: if (x == 1.0) return -1e+299; return f1(1/x,y,z);
	case 13: if (x == 1.0) return -1e+299; return f1(1/x,z,y);
	case 14: if (x == 1.0) return -1e+299; return f2(1/x,y,z);
	case 15: if (x == 1.0) return -1e+299; return f2(1/x,z,y);
	case 16: if (y == 1.0) return -1e+299; return f1(1/y,x,z);
	case 17: if (y == 1.0) return -1e+299; return f1(1/y,z,x);
	case 18: if (y == 1.0) return -1e+299; return f2(1/y,x,z);
	case 19: if (y == 1.0) return -1e+299; return f2(1/y,z,x);
	case 20: if (z == 1.0) return -1e+299; return f1(1/z,x,y);
	case 21: if (z == 1.0) return -1e+299; return f1(1/z,y,x);
	case 22: if (z == 1.0) return -1e+299; return f2(1/z,x,y);
	case 23: if (z == 1.0) return -1e+299; return f2(1/z,y,x);
	}
	throw 1;
}
int main() {
	string s[] = {
		"x^y^z",
		"x^z^y",
		"(x^y)^z",
		"(x^z)^y",
		"y^x^z",
		"y^z^x",
		"(y^x)^z",
		"(y^z)^x",
		"z^x^y",
		"z^y^x",
		"(z^x)^y",
		"(z^y)^x",
	};
	long double x, y, z;
	cin >> x >> y >> z;
	string r = s[0];
	long double w = NN;
	for (int i = 0; i < 12; ++ i) {
		long double ww = f(x, y, z, i);
		if (ww != NN && ww > w+EPS) {
			w = ww;
			r = s[i];
		}
	}
	if (w == NN) {
		for (int i = 0; i < 12; ++ i) {
			long double ww = f(x, y, z, i+12);
			if (ww != NN && -ww > w+EPS) {
				w = -ww;
				r = s[i];
			}
		}
	}
	cout << r << endl;
}
