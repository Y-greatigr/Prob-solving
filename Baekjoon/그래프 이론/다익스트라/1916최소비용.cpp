#include <iostream>
#include <vector>
#include <queue>
#define MAX 987654321

using namespace std;

int N, M, start, dest;
vector<pair<int, int>> graph[1001];
int dist[1001];

void input() {
	cin >> N >> M;
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		graph[a].push_back({ b,c });
	}
	cin >> start >> dest;
	for (int i = 1; i <= N; i++) {
			dist[i] = MAX;
	}
}
void solution() {
	priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start });
	dist[start] = 0;
	
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (cur == dest)
			break;
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int pcost = graph[cur][i].second;
			if (dist[next] > cost + pcost) {
				dist[next] = cost + pcost;
				pq.push({ dist[next] , next });
			}
		}
	}
	cout << dist[dest];
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