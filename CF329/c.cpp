#include <bits/stdc++.h>
using namespace std;
string f(int x, int i) {
	ostringstream o;
	o << "(" << (x/2) << "*((1-abs((t-" << i << ")))+abs((abs((t-" << i << "))-1))))";
	return o.str();
}
int main() {
	int n;
	cin >> n;
	vector<int> x(n), y(n), r(n);
	for (int i = 0; i < n; ++ i) cin >> x[i] >> y[i] >> r[i];
	vector<string> sx(n), sy(n);
	for (int i = 0; i < n; ++ i) {
		sx[i] = f(x[i], i);
		sy[i] = f(y[i], i);
	}
	string xx = sx[0];
	string yy = sy[0];
	for (int i = 1; i < n; ++ i) {
		xx = "(" + xx + "+" + sx[i] + ")";
		yy = "(" + yy + "+" + sy[i] + ")";
	}
	cout << xx << endl;
	cout << yy << endl;
}
