#include <bits/stdc++.h>
using namespace std;
struct XorSequenceEasy {
	int getmax(vector <int> A, int N) {
		map<int,int> a, b;
		for (int i = 0; i < A.size(); ++ i) {
			for (int j = i+1; j < A.size(); ++ j) {
				for (int p = N >> 1; p; p >>= 1) {
					if ((A[i] & p) && !(A[j] & p)) { ++ a[p]; break; }
					if ((A[j] & p) && !(A[i] & p)) { ++ b[p]; break; }
				}
			}
		}
		int r = 0;
		for (int p = 1; p < N; p <<= 1) {
			r += max(a[p], b[p]);
		}
		return r;
	}
};
