#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;	
	int* a = new int[n];
	int* d = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	d[0] = a[0];
	d[1] = a[1] + a[0];
	d[2] = max(a[1] + a[2], a[0] + a[2]);

	for (int i = 3; i < n; i++) {
		d[i] = max(a[i] + a[i - 1] + d[i - 3], a[i] + d[i - 2]);
	}
	cout << d[n - 1];

	delete[] d;
	delete[] a;
	return 0;
}