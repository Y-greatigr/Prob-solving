#include <iostream>
#include <cstring>
using namespace std;

char a[100][100];
bool visited[100][100] = { false };
int cnt = 0;
int n;
char c;
int row[4] = { -1, 0, 0, 1 };
int col[4] = { 0, -1, 1, 0 };

void dfs(int x, int y, char wow){
	if (wow != a[x][y])
		return;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int rx = x + row[i];
		int cy = y + col[i];
		if (rx >= 0 && cy >= 0 && rx < n && cy < n) {
			if (!visited[rx][cy]) {
				dfs(rx, cy, a[x][y]);
			}
		}
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				dfs(i, j, a[i][j]);
				cnt++;
			}
		}
	}
	cout << cnt << " ";
	cnt = 0;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 'G')
				a[i][j] = 'R';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				dfs(i, j, a[i][j]);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}