#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int N, T;
int IC[101][101][4];
bool confi[101][101];
vector<pair<int, int>> sign[13];
void input() {
	cin >> N >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 0; k < 4; k++)
				cin >> IC[i][j][k];
		}
	}
	sign[1].push_back({ -1, 0 });
	sign[1].push_back({ 0, 1 });
	sign[1].push_back({ 1, 0 });

	sign[2].push_back({ 0, -1 });
	sign[2].push_back({ -1, 0 });
	sign[2].push_back({ 0, 1 });

	sign[3].push_back({ -1, 0 });
	sign[3].push_back({ 0, -1 });
	sign[3].push_back({ 1, 0 });

	sign[4].push_back({ 0, -1 });
	sign[4].push_back({ 1, 0 });
	sign[4].push_back({ 0, 1 });

	sign[5].push_back({ -1, 0 });
	sign[5].push_back({ 0, 1 });

	sign[6].push_back({ 0, -1 });
	sign[6].push_back({ -1, 0 });

	sign[7].push_back({ 0, -1 });
	sign[7].push_back({ 1, 0 });

	sign[8].push_back({ 1, 0 });
	sign[8].push_back({ 0, 1 });

	sign[9].push_back({ 0, 1 });
	sign[9].push_back({ 1, 0 });

	sign[10].push_back({ -1, 0 });
	sign[10].push_back({ 0, 1 });

	sign[11].push_back({ -1, 0 });
	sign[11].push_back({ 0, -1 });

	sign[12].push_back({ 0, -1 });
	sign[12].push_back({ 1, 0 });

	memset(confi, false, sizeof(confi));
}
void solution() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {1,1}, 0 });
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int t = q.front().second;
		q.pop();
		if (t > T)
			continue;
		confi[x][y] = true;
		int cur = IC[x][y][t % 4];
		for (int i = 0; i < sign[cur].size(); i++) {
			int row = x + sign[cur][i].first;
			int col = y + sign[cur][i].second;
			if (row<1 || col<1 || row>N || col >N)
				continue;
			q.push({ { row, col}, t + 1 });
		}
	}
	int sum = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (confi[i][j])
				sum++;
		}
	}
	cout << sum;
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