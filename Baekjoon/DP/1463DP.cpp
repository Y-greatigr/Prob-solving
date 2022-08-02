#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int* a = new int[n + 1];
	a[1] = 0;
	for (int i = 2; i <= n; i++) {
		a[i] = a[i - 1] + 1;
		if (i % 2 == 0)
			a[i] = min(a[i], a[i / 2] + 1);
		if (i % 3 == 0)
			a[i] = min(a[i], a[i / 3] + 1);
	}
	cout << a[n];
	return 0;
}