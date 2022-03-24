#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int R, C;
int cur_R, cur_C;
int end_R, end_C;
char maze[1000][1000];
int visited[1000][1000];
int row[4] = { 0,0,-1,1 };
int col[4] = { -1,1,0,0 };
int flag = 0;
queue<pair<int, int>> q;

 void input() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == 'M') {
				cur_R = i; cur_C = j;
			}
		}
	}
	memset(visited, -1, sizeof(visited));
}
void bfs() {
	visited[cur_R][cur_C] = 0;
	q.push({ cur_R,cur_C });
	while (!q.empty()) {
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int rx = r + row[i];
			int cy = c + col[i];
			if (rx < 0)
				rx = R - 1;
			else if (rx >= R)
				rx = 0;
			if (cy < 0)
				cy = C - 1;
			else if (cy >= C)
				cy = 0;
			if (maze[rx][cy] == 'D') {
				flag = 1;
				end_R = rx;
				end_C = cy;
				visited[rx][cy] = visited[r][c] + 1;
				return;
			}
			if (visited[rx][cy]!=-1 || maze[rx][cy] == '#')
				continue;
			visited[rx][cy] = visited[r][c] + 1;
			q.push({ rx,cy });
		}
	}
}
void restore() {
	int r = end_R;
	int c = end_C;
	while (visited[r][c]) {
		for (int i = 0; i < 4; i++) {
			int rx = r + row[i];
			int cy = c + col[i];
			if (rx < 0)
				rx = R - 1;
			else if (rx >= R)
				rx = 0;
			if (cy < 0)
				cy = C - 1;
			else if (cy >= C)
				cy = 0;
			if (visited[rx][cy] != visited[r][c] - 1)
				continue;
			if(visited[rx][cy])
				maze[rx][cy] = 'x';
			r = rx;
			c = cy;
			break;
		}
	}
}
void solution() {
	bfs();
	if (!flag) {
		cout << "NO";
		return;
	}
	restore();
	cout << "YES" << '\n';
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << maze[i][j];
		}
		cout << '\n';
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