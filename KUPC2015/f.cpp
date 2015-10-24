#include <bits/stdc++.h>
using namespace std;
string S;
struct T {
	char c;
	T* l;
	T* r;
	T(char c) : c(c), l(nullptr), r(nullptr) {}
	T(char c, T* l, T* r) : c(c), l(l), r(r) {}
};
int main() {
	cin >> S;
	stack<T*> s;
	for (int i = 0; i < S.length(); ++ i) {
		if (isdigit(S[i])) {
			s.push(new T(S[i]));
		} else {
			auto x = s.top(); s.pop();
			auto y = s.top(); s.pop();
			s.push(new T(S[i], x, y));
		}
	}
	string r;
	queue<T*> q;
	q.push(s.top());
	while (!q.empty()) {
		auto x = q.front(); q.pop();
		r += x->c;
		if (x->l && x->r) {
			q.push(x->r);
			q.push(x->l);
		}
	}
	reverse(r.begin(), r.end());
	cout << r << endl;
}
