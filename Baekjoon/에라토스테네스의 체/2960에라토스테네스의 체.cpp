#include <iostream>
using namespace std;
bool a[1001] = { false, };
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;

	int count = 1;
	int i = 2;

	while (1) {
		for (int p = 1; p < n; p++) {
			if (count == k && !a[p * i]) {
				if (p * i > n) {
					i++;
					break;
				}
				cout << p * i;
				return 0;
			}
			if (p * i > n) {
				i++;
				break;
			}
			if (!a[p * i]) {
				a[p * i] = true;
				count++;
			}
		}
	}

	return 0;
}