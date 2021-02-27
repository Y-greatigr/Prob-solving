#include <iostream>
#include <queue>
using namespace std;

int a[100][100];
int b[100][100];
int x[4] = { 0,0,-1,1 };
int y[4] = { -1,1,0,0 };
bool visited[100][100] = { false };

void pre(int n, int height) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
			if (a[i][j] > height)
				b[i][j] = 1;
			else {
				b[i][j] = 0;
			}
		}
	}
}
void dfs(int n, int p, int e) {
	visited[p][e] = true;
	for (int i = 0; i < 4; i++) {
		int rx = p + x[i];
		int yc = e + y[i];
		if (rx < 0 || rx >= n || yc < 0 || yc >= n)
			continue;
		if (b[rx][yc] && !visited[rx][yc]) {
			visited[rx][yc] = true;
			dfs(n, rx, yc);
		}
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n; cin >> n;
	int maxHeight = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] > maxHeight)
				maxHeight = a[i][j];
		}
	}
	int wow;
	int cnt = 1;
	for (int i = 0; i < 100; i++) {
		if (maxHeight < i)
			break;
		wow = 0;
		pre(n, i);
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++)
				if (!visited[j][k] && b[j][k] == 1) {
					dfs(n, j, k);
					wow++;
				}
		}
		if (wow > cnt)
			cnt = wow;
	}
	cout << cnt;
	return 0;
}