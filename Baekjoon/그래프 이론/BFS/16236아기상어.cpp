#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
int a[20][20];
bool visited[20][20] = { false };
int n, init = 2, prey_num = 0, cnt = 0;
int row[4] = { -1, 0, 0, 1 };
int col[4] = { 0, -1, 1, 0 };

bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	int ax, ay, acnt;
	int bx, by, bcnt;
	ax = a.first.first;
	ay = a.first.second;
	acnt = a.second;
	bx = b.first.first;
	by = b.first.second;
	bcnt = b.second;
			// 가장 위에
	if (acnt == bcnt) {
		if (ax == bx) {
			return ay < by;
		}
		// 가장 왼쪽
		else return ax < bx;
	}
	// 거리 순
	else return acnt < bcnt;
}
void bfs(int x, int y) {
	queue < pair<pair<int, int>, int>> q;
	vector < pair<pair<int, int>, int>>v;
	q.push({ { x, y }, 0 });
	visited[x][y] = true;
	while(1){
		while (!q.empty()) {
			int ro = q.front().first.first;
			int co = q.front().first.second;
			int count = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = ro + row[i];
				int yy = co + col[i];
				if (xx >= 0 && xx < n && yy >= 0 && yy < n) {
					if ((a[xx][yy] == 0 || a[xx][yy] == init) && !visited[xx][yy]) { // 0이거나 크기가 같을 때 지나간다
						q.push({ { xx,yy }, count + 1 });
						visited[xx][yy] = true;
					}
					else if (a[xx][yy] > 0 && a[xx][yy] < init && !visited[xx][yy]) { // 보다 작은 물고기는 먹는다.
						v.push_back({ { xx,yy }, count + 1 });
						q.push({ { xx,yy }, count + 1 });
						visited[xx][yy] = true;
					}
					else {} // 엄마 상어 부르거나 덩치 더 키우고 와야 함
				}
			}
		}
		if (v.size() == 0)
			return;
		sort(v.begin(), v.end(), cmp);
		int i, j, c;
		i = v.front().first.first;
		j = v.front().first.second;
		c = v.front().second;
		prey_num += 1;
		cnt += c;
		a[i][j] = 0;
		memset(visited, false, sizeof(visited));
		visited[i][j] = true;
		q.push({ { i, j }, 0 });
		v.clear();
		if (prey_num == init) {
			init++;
			prey_num = 0;
		}
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	int x = 0, y = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 9) {
				x = i;
				y = j;
				a[i][j] = 0;
			}
		}
	}
	bfs(x, y);
	cout << cnt;
	return 0;
}