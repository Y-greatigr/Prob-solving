#include <iostream>

using namespace std;
int n, m;
int b[8] = { 0 };
void wow(int ind, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << b[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = ind; i <= n; i++) {
		b[cnt] = i;
		wow(i, cnt + 1);
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	wow(1, 0);
	return 0;
}