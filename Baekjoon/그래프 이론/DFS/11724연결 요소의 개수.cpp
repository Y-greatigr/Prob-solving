#include <iostream>
using namespace std;
int a[1001][1001];
bool b[1001];
int ans = 0;
void dfs(int k) {
	if (b[k])
		return;
	b[k] = true;
	for (int i = 1; i < 1001; i++) {
		if (a[k][i] == 1 && !b[i])
			dfs(i);
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m, x, y;
	cin >> n >> m;

	while (m--) {
		cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
	}
	
	for (int i = 1; i <= n; i++) {
		if (!b[i])
			ans++;
		dfs(i);
	}

	cout << ans;
	return 0;
}