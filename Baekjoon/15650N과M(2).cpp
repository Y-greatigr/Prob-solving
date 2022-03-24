#include <iostream>

using namespace std;
int n, m;
bool a[9] = { false };
void wow(int ind, int cnt) {
	if (cnt == m) {
		for (int i = 1; i <= n; i++) {
			if (a[i])
				cout << i << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = ind; i <= n; i++) {
		if (a[i])
			continue;
		a[i] = true;
		wow(i, cnt + 1);
		a[i] = false;
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	wow(1, 0);
	return 0;
}