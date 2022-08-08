#include <iostream>
#include <string>
using namespace std;
bool isconse(string s) {
	bool alpha[26] = {false, };
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		if (alpha[c - 'a'])
			return false;
		while (true) {
			alpha[c - 'a'] = true;
			if (c != s[++i]) {
				i--;
				break;
			}
		}
	}
	return true;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, count = 0;
	string num;
	cin >> n;
	while (n--) {
		cin >> num;
		if (isconse(num))
			count++;
	}
	cout << count;
	return 0;
}