#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int al[100] = { 0, };
	string a;
	cin >> a;

	for (char c : a) {
		if (c >= 'a')
			c = c - 32;
		al[c]++;
	}

	int k = 0;
	char d = '?';

	for (int b = 'A'; b <= 'Z'; b++) {
		if (al[b] > k) {
			k = al[b];
			d = b;
		}
		else if (al[b] == k) {
			d = '?';
		}
	}
	cout << d;
	return 0;

}