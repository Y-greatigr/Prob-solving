#include <iostream>
#include <climits>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int H, W;
char map[26][26];
bool visited[26][26];
int cx[4] = { 0, 0, -1, 1 };
int cy[4] = { -1,1,0,0 };

void input() {
	cin >> H >> W;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++)
			cin >> map[i][j];
	}
}
void solution() {
	int x, y;
	int min = INT_MAX;
	string ans = "";
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			if (map[i][j] == '.')
				continue;
			memset(visited, false, sizeof(visited));
			queue<pair<pair<int, int>,int>> q;
			q.push({ {i,j}, 0 });
			visited[i][j] = true;
			while (!q.empty()) {
				int xx = q.front().first.first;
				int yy = q.front().first.second;
				//int cnt = q.front().second;
				q.pop();
				for (int k = 0; k < 4; k++) {
					int row = xx + cx[k];
					int col = yy + cy[k];
					if (row<1 || row>H || col<1 || col>W || map[row][col] == '.' || visited[row][col])
						continue;

					memset(visited, false, sizeof(visited));
				}
			}
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