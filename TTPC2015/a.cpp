#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	if (s[2] == 'B') {
		cout << "Bachelor " << s.substr(0,2) << endl;
	} else if (s[2] == 'M')	 {
		cout << "Master " << s.substr(0,2) << endl;
	} else {
		cout << "Doctor " << s.substr(0,2) << endl;
	}
}
