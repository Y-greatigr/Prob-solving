#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	long long* a = new long long[n];
	a[0] = 1;
	a[1] = 2;
	for (int i = 2; i < n; i++) {
		a[i] = (a[i - 1] + a[i - 2]) % 10007;
	}
	cout << a[n - 1];
	delete[]a;
	return 0;
}