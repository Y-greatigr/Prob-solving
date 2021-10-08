#include <iostream>
#include <climits>
#include <queue>
using namespace std;

int m, n;
int arr[1000][1000];
int check[1000][1000];
int x[4] = { 0,0,-1,1 };
int y[4] = { -1,1,0,0 };
void solution() {
	priority_queue < pair<int, pair<int, int>>, vector< pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({ arr[0][0],{0,0} });
	while (!pq.empty()) {
		int cur_num = pq.top().first;
		int cur_x = pq.top().second.first;
		int cur_y = pq.top().second.second;
		pq.pop();
		if (check[cur_x][cur_y] <= cur_num)continue;
		check[cur_x][cur_y] = cur_num;
		if (cur_x == m - 1 && cur_y == n - 1)break;
		for (int i = 0; i < 4; i++) {
			int next_x = cur_x + x[i];
			int next_y = cur_y + y[i];
			int next_num = cur_num + arr[next_x][next_y];
			if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || next_num >= check[next_x][next_y] || arr[next_x][next_y] == -1)
				continue;
			pq.push({ next_num,{next_x, next_y} });
		}
	}
	if (check[m - 1][n - 1] == INT_MAX)cout << -1;
	else cout << check[m - 1][n - 1];
}
void input() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			check[i][j] = INT_MAX;
		}
	}
}
void confirm() {
	if (arr[0][0] == -1 || arr[m - 1][n - 1] == -1) {
		cout << -1;
		exit(0);
	}
}
void solve() {
	input();
	confirm();
	solution();
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}