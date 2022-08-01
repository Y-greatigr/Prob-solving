#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int** a = new int* [n];
	int** b = new int* [n + 1];
	for (int i = 0; i < n; i++) {
		a[i] = new int[3];
		b[i] = new int[3];
		cin >> a[i][0] >> a[i][1] >> a[i][2];
	}
	b[n] = new int[3];
	b[0][0] = b[0][1] = b[0][2] = 0;
	for (int i = 1; i <= n; i++) {
		b[i][0] = min(b[i - 1][1], b[i - 1][2]) + a[i - 1][0];
		b[i][1] = min(b[i - 1][0], b[i - 1][2]) + a[i - 1][1];
		b[i][2] = min(b[i - 1][0], b[i - 1][1]) + a[i - 1][2];
	}
	cout << min(min(b[n][0], b[n][1]), b[n][2]);
	return 0;
}