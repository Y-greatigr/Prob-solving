#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int i = 1;
	while (1) {
		if (n == 1)
			break;
		if (n % 2 == 0)
			n = n / 2;
		else
			n = n * 3 + 1;
		i++;
	}
	cout << i;
	return 0;
}