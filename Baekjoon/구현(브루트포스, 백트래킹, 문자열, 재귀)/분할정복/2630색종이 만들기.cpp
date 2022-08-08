#include <iostream>
using namespace std;

int a[128][128];
int blue_count = 0;
int white_count = 0;

void cnt(int x, int y, int n) {
	int tmp = 0;
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++)
			if (a[i][j])
				tmp++;
	}
	if (tmp == n * n)
		blue_count++;
	else if (!tmp)
		white_count++;
	else {
		cnt(x, y, n / 2);
		cnt(x + n / 2, y, n / 2);
		cnt(x, y + n / 2, n / 2);
		cnt(x + n / 2, y + n / 2, n / 2);
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
	cnt(0, 0, n);
	cout << white_count << '\n';
	cout << blue_count << '\n';
	return 0;
}