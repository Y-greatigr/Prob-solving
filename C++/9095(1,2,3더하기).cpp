#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, f;
	cin >> n;
	int a[11];
	a[1] = 1;
	a[2] = 2;
	a[3] = 4;
	for (int i = 4; i <= 10; i++) {
		a[i] = a[i - 1] + a[i - 2] + a[i - 3];
	}
	for (int i = 0; i < n; i++) {
		cin >> f;
		cout << a[f] << '\n';
	}
	return 0;
}