#include <iostream>
using namespace std;
int n, m, maxi = 0;
int a[500][500];
bool visited[500][500] = { false };
int row[4] = { -1, 0, 0, 1 };
int col[4] = { 0, -1, 1, 0 };

void dfs(int x, int y, int cnt, int value) {
	if (cnt > 3) {
		maxi = value > maxi ? value : maxi;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int rx = x + row[i];
		int cy = y + col[i];
		if (rx >= 0 && cy >= 0 && rx < n && cy < m && !visited[rx][cy]) {
			visited[rx][cy] = true;
			dfs(rx, cy, cnt + 1, value + a[rx][cy]);
			visited[rx][cy] = false;
		}
	}
}
void wow(int x, int y) {
	int sum;
	if (x + 2 < n && y + 1 < m) { //た
		sum = a[x][y] + a[x + 1][y] + a[x + 2][y] + a[x + 1][y + 1];
		maxi = sum > maxi ? sum : maxi;
	}
	if (x + 2 < n && y - 1 >= 0) { //っ
		sum = a[x][y] + a[x + 1][y] + a[x + 2][y] + a[x + 1][y - 1];
		maxi = sum > maxi ? sum : maxi;
	}
	if (x - 1 >= 0 && y + 2 < m) { //で
		sum = a[x][y] + a[x - 1][y + 1] + a[x][y + 1] + a[x][y + 2];
		maxi = sum > maxi ? sum : maxi;
	}
	if (x + 1 < n && y + 2 < m) { //ぬ
		sum = a[x][y] + a[x + 1][y + 1] + a[x][y + 1] + a[x][y + 2];
		maxi = sum > maxi ? sum : maxi;
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> a[i][j];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = true;
			dfs(i, j, 1, a[i][j]);
			visited[i][j] = false;
			wow(i, j);
		}
	}

	cout << maxi;
	return 0;
}