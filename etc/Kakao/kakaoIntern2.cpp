#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int row[4] = { 0,0,1,-1 };
int col[4] = { 1,-1,0,0 };
int bfs(vector<string> a, int x, int y) {
	bool visited[5][5] = { false, };
	queue<pair<pair<int, int>, int>> q;
	q.push({ { x, y }, 0 });
	visited[x][y] = true;
	while (!q.empty()) {
		int i = q.front().first.first;
		int j = q.front().first.second;
		int count = q.front().second;
		q.pop();
		if (count >= 2)
			continue;
		for (int w = 0; w < 4; w++) {
			int rx = i + row[w];
			int cy = j + col[w];
			if (rx < 0 || rx>4 || cy < 0 || cy>4 || visited[rx][cy])
				continue;
			if (a[rx][cy] == 'X')
				continue;
			else if (a[rx][cy] == 'O') {
				q.push({ {rx,cy},count + 1 });
			}
			else {
				return 0;
			}
		}
	}
	return 1;
}
vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;
	for (int i = 0; i < 5; i++) {
		bool flag = true;
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				if (places[i][j][k] == 'P') {
					if (!bfs(places[i], j, k)) {
						flag = false;
						j = 4;
						break;
					}
				}
			}
		}
		if (flag)
			answer.push_back(1);
		else
			answer.push_back(0);
	}
	return answer;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<vector<string>> places = { {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},{"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},{"PXOPX", "OXOXP", "OXPXX", "OXXXP", "POOXX"},{"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},{"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP" } };
	vector<int> a = solution(places);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	return 0;
}