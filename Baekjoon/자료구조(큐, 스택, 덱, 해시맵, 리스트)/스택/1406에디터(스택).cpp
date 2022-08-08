#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string s; cin >> s;
	stack<char> left;
	stack<char> right;
	for (int i = 0; i < s.length(); i++)
		left.push(s[i]);
	char c;
	int n; cin >> n;

	while (n--) {
		cin >> c;
		if (c == 'L') {
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		}
		else if (c == 'D') {
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		else if (c == 'B') {
			if (!left.empty())
				left.pop();
		}
		else {
			cin >> c;
			left.push(c);
		}
	}
	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}
	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}
	return 0;
}