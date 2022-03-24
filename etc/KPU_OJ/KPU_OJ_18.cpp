#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int start, des;
int visited[3500];
vector<int> v[3500];

void input() {
	cin >> N >> M;
	int a, b;
	while (M--) {
		cin >> a >> b;
		v[a - 1].emplace_back(b - 1);
		v[b - 1].emplace_back(a - 1);
	}
	cin >> a >> b;
	start = a - 1; des = b - 1;
	memset(visited, -1, sizeof(visited));
}
void solution() {
	queue<int> q;
	q.push(start);
	visited[start] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == des) {
			cout << visited[cur];
			return;
		}
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (visited[next] != -1)
				continue;
			visited[next] = visited[cur] + 1;
			q.push(next);
		}
	}
	cout << 0;
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