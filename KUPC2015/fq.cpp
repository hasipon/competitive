#include <bits/stdc++.h>
using namespace std;

int main() {
	string S, T;
	cin >> S;
	queue<int> q;
	for (int i = 0; i < S.length(); ++ i) {
		if (isdigit(S[i])) {
			q.push(S[i]-'0');
		} else {
			int r = q.front(); q.pop();
			int l = q.front(); q.pop();
			switch (S[i]) {
			case '+': q.push(r + l); break;
			case '-': q.push(r - l); break;
			case '*': q.push(r * l); break;
			case '/': q.push(r / l); break;
			default: throw 1;
			}
		}
	}
	cout << q.front() << endl;
}
