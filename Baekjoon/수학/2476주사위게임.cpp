#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	int max = 0;
	while (n--) {
		int x, y, z;
		int money = 0;
		cin >> x >> y >> z;

		if (x == y && y == z)
			money = 10000 + x * 1000;
		else if (x == y || x == z)
			money = 1000 + x * 100;
		else if (y == z)
			money = 1000 + y * 100;
		else {
			int w = x > y ? x : y;
			w = w > z ? w : z;
			money = w * 100;
		}

		if (money > max)
			max = money;
	}
	cout << max;
	return 0;
}