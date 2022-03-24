#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	long long a[100];
	a[0] = 1;
	a[1] = 1;
	a[2] = 1;
	a[3] = 2;
	a[4] = 2;
	for (int i = 5; i < 100; i++) {
		a[i] = a[i - 1] + a[i - 5];
	}
	while (n--) {
		int p;
		cin >> p;
		cout << a[p - 1] << '\n';
	}

	return 0;
}