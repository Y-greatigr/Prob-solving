#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N, M;
int modi[101] = { 0 };
int dis[101] = { 0 };
void input() {
	cin >> N >> M;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		modi[a] = b;
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		modi[a] = b;
	}
}
void solution() {
	queue<int> q;
	q.push(1);
	memset(dis, -1, sizeof(dis));
	dis[1] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++) {
			int next = cur + i;
			if (next > 100)
				continue;
			if (modi[next] != 0)
				next = modi[next];
			if (dis[next] == -1) {
				dis[next] = dis[cur] + 1;
				q.push(next);
			}
		}
	}
	cout << dis[100];
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