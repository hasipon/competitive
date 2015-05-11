#include <bits/stdc++.h>
using namespace std;
struct ShadowSculpture {
	int n;
	vector<vector<vector<bool>>> a;
	vector<string> xy, yz, zx;
	void dfs(int i, int j, int k) {
		if (!(0 <= i && i < n && 0 <= j && j < n && 0 <= k && k < n)) return;
		if (a[i][j][k]) return;
		a[i][j][k] = true;
		xy[i][j] = 'Y';
		yz[j][k] = 'Y';
		zx[k][i] = 'Y';
		dfs(i+1, j, k);
		dfs(i-1, j, k);
		dfs(i, j+1, k);
		dfs(i, j-1, k);
		dfs(i, j, k+1);
		dfs(i, j, k-1);
	}
	bool f(vector <string> XY, vector <string> YZ, vector <string> ZX) {
		n = XY.size();
		a = vector<vector<vector<bool>>>(n, vector<vector<bool>>(n, vector<bool>(n)));
		for (int i = 0; i < n; ++ i) for (int j = 0; j < n; ++ j) {
			if (XY[i][j] == 'N') for (int k = 0; k < n; ++ k) a[i][j][k] = true;
			if (YZ[i][j] == 'N') for (int k = 0; k < n; ++ k) a[k][i][j] = true;
			if (ZX[i][j] == 'N') for (int k = 0; k < n; ++ k) a[j][k][i] = true;
		}
		bool r = true;
		for (int i = 0; i < n; ++ i) for (int j = 0; j < n; ++ j) for (int k = 0; k < n; ++ k) if (!a[i][j][k]) {
			xy = vector<string>(n, string(n, 'N'));
			yz = vector<string>(n, string(n, 'N'));
			zx = vector<string>(n, string(n, 'N'));
			dfs(i, j, k);
			if (XY == xy && YZ == yz && ZX == zx) return true;
			r = false;
		}
		if (r) {
			for (string s : XY) if (s.find('Y') != string::npos) return false;
			for (string s : YZ) if (s.find('Y') != string::npos) return false;
			for (string s : ZX) if (s.find('Y') != string::npos) return false;
			return true;
		}
		return false;
	}
	string possible(vector <string> XY, vector <string> YZ, vector <string> ZX) {
		return f(XY, YZ, ZX) ? "Possible" : "Impossible";
	}
};
