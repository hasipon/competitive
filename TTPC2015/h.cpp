#include <bits/stdc++.h>
using namespace std;
typedef complex<long> P;
long cross(const P& a, const P& b) {
	return imag(conj(a)*b);
}
long dot(const P& a, const P& b) {
	return real(conj(a)*b);
}
int main() {
	int N;
	cin >> N;
	vector<P> p;
	for (int i = 0; i < N; ++ i) {
		int x, y;
		cin >> x >> y;
		p.push_back(P(x,y));
	}
	long r = 1L<<60;
	for (int i = 0; i < N; ++ i) {
		for (int j = i+1; j < N; ++ j) {
			if (cross(p[i], p[j]) != 0) {
				for (int k = j+1; k < N; ++ k) {
					if (cross(p[j], p[k]) == 0) continue;
					if (cross(p[k], p[i]) == 0) continue;
					long c1 = cross(p[i]-p[j], p[i]);
					long c2 = cross(p[j]-p[k], p[j]);
					long c3 = cross(p[k]-p[i], p[k]);
					if ((c1 < 0 && c2 < 0 && c3 < 0) || (c1 > 0 && c2 > 0 && c3 > 0)) {
						r = min(r, abs(cross(p[j]-p[i], p[k]-p[i])));
					}
				}
			} else if (dot(p[i], p[j]) < 0) {
				long r1 = 1L<<60;
				long r2 = 1L<<60;
				for (int k = 0; k < N; ++ k) {
					long c = cross(p[j]-p[i], p[k]-p[i]);
					if (c < 0) {
						r1 = min(r1, -c);
					} else if (c > 0) {
						r2 = min(r2, c);
					}
				}
				r = min(r, r1 + r2);
			}
		}
	}
	if (r == 1L<<60) {
		printf("Impossible\n");
	} else {
		printf("Possible\n%f\n", r/2.0);
	}
}
