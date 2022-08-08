#include <iostream>

using namespace std;
int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, x;
	cin >> n;
	int a[10001] = { 0, };
	for (int i = 0; i < n; i++) {
		cin >> x;
		a[x]++;
	}
	for (int i = 1; i < 10001; i++) {
		if (a[i] > 0) {
			for (int j = 0; j < a[i]; j++) {
				cout << i << '\n';
			}
		}
	}
	return 0;
}