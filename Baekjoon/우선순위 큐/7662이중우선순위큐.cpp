#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t; cin >> t;
	while (t--) {
		priority_queue<int, vector<int>, greater<int>> uq;
		priority_queue<int, vector<int>, less<int>> dq;
		map<int, int> m;
		int k; cin >> k;
		while (k--) {
			char c; int n; cin >> c >> n;
			if (c == 'I') {
				uq.push(n);
				dq.push(n);
				m[n]++;
			}
			else {
				if (n == -1) {
					while (!uq.empty() && m[uq.top()] == 0)
						uq.pop();
					if (!uq.empty()) {
						m[uq.top()]--;
						uq.pop();
					}
				}
				else {
					while (!dq.empty() && m[dq.top()] == 0)
						dq.pop();
					if (!dq.empty()) {
						m[dq.top()]--;
						dq.pop();
					}
				}
			}
		}
		while (!uq.empty() && m[uq.top()] == 0)
			uq.pop();
		while (!dq.empty() && m[dq.top()] == 0)
			dq.pop();
		if (dq.empty() && uq.empty())
			cout << "EMPTY" << '\n';
		else
			cout << dq.top() << " " << uq.top() << '\n';
	}
	return 0;
}