#include <iostream>

using namespace std;
char a[2187][2187];

void star(int n, int x, int y) {
	if (n == 3) {
		a[x][y] = '*';
		a[x + 1][y] = '*';
		a[x + 2][y] = '*';

		a[x][y + 1] = '*';
		a[x + 2][y + 1] = '*';

		a[x][y + 2] = '*';
		a[x + 1][y + 2] = '*';
		a[x + 2][y + 2] = '*';

		return;
	}
	int b = n / 3;

	star(b, x, y);
	star(b, x, y + b);
	star(b, x, y + 2 * b);

	star(b, x + b, y);
	star(b, x + b, y + 2 * b);

	star(b, x + 2 * b, y);
	star(b, x + 2 * b, y + b);
	star(b, x + 2 * b, y + 2 * b);
}
int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			a[i][j] = ' ';
	}
	star(n, 0, 0);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << a[i][j];
		cout << "\n";
	}


	return 0;
}