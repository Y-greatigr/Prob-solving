#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int R, C;
char ar[101][101];
int visited[101][101];
int xx[4] = { 0,0,-1,1 };
int yy[4] = { 1,-1,0,0 };
void input() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++)
			cin >> ar[i][j];
	}
	memset(visited, 0, sizeof(visited));
}
void solution() {
	queue<pair<int,int>> q;
	int ans = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (visited[i][j] || ar[i][j]=='.')continue;
			queue<pair<int, int>> q;
			q.push({ i,j });
			visited[i][j] = 1;
			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				visited[x][y] = 1;
				for (int k = 0; k < 4; k++) {
					int row = x + xx[k];
					int col = y + yy[k];
					if (row < 0 || col < 0 || row >= R || col >= C || visited[row][col] || ar[row][col]=='.')continue;
					visited[row][col] = 1;
					q.push({ row,col });
				}
			}
			ans++;
		}
	}
	cout << ans;
}
void solve() {
	input();
	solution();
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}