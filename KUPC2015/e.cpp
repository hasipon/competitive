#include <bits/stdc++.h>
using namespace std;
double g(int x, int y, double z) {
	double t1 = M_PI * z / 180;
	double t2 = M_PI * (z+120) / 180;
	double t3 = M_PI * (z+240) / 180;
	double x1 = cos(t1);
	double x2 = cos(t2);
	double x3 = cos(t3);
	double y1 = sin(t1);
	double y2 = sin(t2);
	double y3 = sin(t3);
	double dx = max({x1, x2, x3}) - min({x1, x2, x3});
	double dy = max({y1, y2, y3}) - min({y1, y2, y3});
	return min(x / dx, y / dy);
}
double f(int x, int y) {
	double r1 = sqrt((double)y*y + (double)x*x*4) / 2;
	if (y >= r1) return r1;
	double r = max(g(x,y,0), g(x,y,15));
	double z0 = 0, z3 = 15;
	for (int i = 0; i < 100; ++ i) {
		double z1 = (z0*2 + z3) / 3;
		double z2 = (z0 + z3*2) / 3;
		double g1 = g(x,y,z1);
		double g2 = g(x,y,z2);
		r = max({r, g1, g2});
		if (g1 < g2) {
			z0 = z1;
		} else {
			z3 = z2;
		}
	}
	return r * sqrt(3);
}
int main() {
	int T;
	cin >> T;
		for (int tt = 0; tt < T; ++ tt) {
		int H, W;
		cin >> H >> W;
		printf("%.7f\n", f(min(H,W), max(H,W)));
	}
}
