#include <bits/stdc++.h>
using namespace std;
int main() {
	string s;
	cin >> s;
	size_t pos = 0;
	while (pos < s.length()) {
		pos = s.find("ST", pos);
		if (pos == string::npos) break;
		s.erase(pos, 2);
		if (pos > 0) -- pos;
	}
	cout << s.length() << endl;
}
