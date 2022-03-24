#include <iostream>

using namespace std;
int** a;
int m_cnt = 0, z_cnt = 0, p_cnt = 0;
void func(int x, int y, int n) {
	bool t = true;
	int tmp = 0;
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (a[i][j] != 0)
				t = false;
			tmp += a[i][j];
		}
	}
	if (tmp == 0 && t)
		z_cnt++;
	else if (tmp == n * n)
		p_cnt++;
	else if (tmp == -1 * n * n)
		m_cnt++;
	else {
		func(x, y, n / 3);
		func(x + n / 3, y, n / 3);
		func(x + 2 * n / 3, y, n / 3);
		func(x, y + n / 3, n / 3);
		func(x + n / 3, y + n / 3, n / 3);
		func(x + 2 * n / 3, y + n / 3, n / 3);
		func(x, y + 2 * n / 3, n / 3);
		func(x + n / 3, y + 2 * n / 3, n / 3);
		func(x + 2 * n / 3, y + 2 * n / 3, n / 3);
	}
}
int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	
	a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}

	func(0, 0, n);

	cout << m_cnt << '\n' << z_cnt << '\n' << p_cnt;
	return 0;
}