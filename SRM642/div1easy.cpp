#include <bits/stdc++.h>
using namespace std;
struct WaitingForBus {
	double whenWillBusArrive(vector <int> time, vector <int> prob, int s) {
		vector<double> P(300000);
		P[0] = 1;
		for (int t = 0; t < s; ++ t) if (P[t] > 0) {
			for (int i = 0; i < time.size(); ++ i) {
				P[t + time[i]] += P[t] * prob[i] / 100;
			}
		}
		double r = 0;
		for (int t = s + 1; t < P.size(); ++ t) {
			r += P[t] * (t - s);
		}
		return r;
	}
};
