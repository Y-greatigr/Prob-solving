#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int* a = new int[n + 1];
	a[0] = 0;
	a[1] = 1;
	for (int i = 2; i <= n; i++) {
		int mind = 5;
		for (int j = 1; j * j <= i; j++) {
			int tmp = i - j * j;
			mind = min(mind, a[tmp]);
		}
		a[i] = mind + 1;
	}
	cout << a[n];
	delete[]a;
	return 0;
}