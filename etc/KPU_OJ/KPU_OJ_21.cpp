#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char farm[10][10];
int visited[10][10];
int row[4] = { 0,0,-1,1 };
int col[4] = { -1,1,0,0 };
int r, c;

void input() {
	char d;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> d;
			farm[i][j] = d;
			if (d == 'L') {
				r = i; c = j;
			}
		}
	}
	memset(visited, -1, sizeof(visited));
}
void solution() {
	queue<pair<int, int>> q;
	q.push({ r,c });
	visited[r][c] = 0;
	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();
		if (farm[cur_x][cur_y] == 'B') {
			cout << visited[cur_x][cur_y] - 1;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int rx = cur_x + row[i];
			int cy = cur_y + col[i];
			if (rx < 0 || rx >= 10 || cy < 0 || cy >= 10)
				continue;
			if (farm[rx][cy] == 'R' || visited[rx][cy] != -1)
				continue;
			visited[rx][cy] = visited[cur_x][cur_y] + 1;
			q.push({ rx,cy });
		}
	}
}
void solve() {
	input();
	solution();
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}