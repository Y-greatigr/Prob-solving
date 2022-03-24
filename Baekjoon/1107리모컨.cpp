#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
bool a[10] = { false };
bool ch(int n) {
	string s = to_string(n);
	for (int i = 0; i < s.length(); i++) {
		if (a[s[i] - '0'])
			return false;
	}
	return true;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n, m; cin >> n >> m;
	
	while (m--) {
		int k; cin >> k;
		a[k] = true;
	}
	int mini = abs(n - 100);
	int wow = 2 * n - 100;
	if (wow < 100)
		wow = 100;
	for (int i = 0; i <= wow; i++) {
		if (ch(i)) {
			int k = abs(n - i) + to_string(i).length();
			mini = min(mini, k);
		}
	}
	cout << mini;
	return 0;
}