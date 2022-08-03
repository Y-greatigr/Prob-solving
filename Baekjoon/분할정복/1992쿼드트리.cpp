#include <iostream>
#include <string>
using namespace std;
int** a;
string ans = "";

void quard(int x, int y, int size) {
	int tmp = 0;
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++)
			tmp += a[i][j];
	}
	if (tmp == size * size)
		ans += "1";
	else if (tmp == 0)
		ans += "0";
	else {
		ans += "(";
		quard(x, y, size / 2);
		quard(x, y + size / 2, size / 2);
		quard(x + size / 2, y, size / 2);
		quard(x + size / 2, y + size / 2, size / 2);
		ans += ")";
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	string s;
	a = new int* [n];

	for (int i = 0; i < n; i++) {
		cin >> s;
		a[i] = new int[n];
		for (int j = 0; j < n; j++) {
			a[i][j] = s[j]-'0';
		}
	}

	quard(0, 0, n);
	cout << ans;
	return 0;
}