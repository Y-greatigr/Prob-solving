#include <iostream>
#include <string>
using namespace std;
int a[10000] = { 0, };
int b[10000] = { 0, };
int c[10001] = { 0, };
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string aa, bb;
	cin >> aa >> bb;
	int k = 0;
	for (int i = aa.length() - 1; i >= 0; i--) {
		a[k++] = aa[i] - '0';
	}
	k = 0;
	for (int i = bb.length() - 1; i >= 0; i--) {
		b[k++] = bb[i] - '0';
	}

	int j = aa.length() > bb.length() ? aa.length() : bb.length();
	for (k = 0; k < j; k++) {
		int tmp = a[k] + b[k];
		c[k] += tmp % 10;
		if (c[k] >= 10) {
			c[k + 1] += 1;
			c[k] %= 10;
		}
		else
			c[k + 1] += tmp / 10;
	}
	if (c[j] == 0) {
		for (k = j - 1; k >= 0; k--)
			cout << c[k];
	}
	else {
		for (k = j; k >= 0; k--)
			cout << c[k];
	}
	return 0;
}