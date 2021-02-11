#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, t, k = 0;
	cin >> n;
	for (int i = 0; i < 5; i++) {
		cin >> t;
		if (n == t)
			k++;
	}
	cout << k;
	return 0;
}