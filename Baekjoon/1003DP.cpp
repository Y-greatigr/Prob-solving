#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int a[41][2];
	a[0][0] = 1;
	a[0][1] = 0;
	a[1][0] = 0;
	a[1][1] = 1;
	for (int i = 2; i <= 40; i++) {
		a[i][0] = a[i - 1][0] + a[i - 2][0];
		a[i][1] = a[i - 1][1] + a[i - 2][1];
	}

	int n;
	cin >> n;

	int k;
	while (n--) {
		cin >> k;
		cout << a[k][0] << " " << a[k][1] << '\n';
	}
	return 0;
}