#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX 10000000
int V, E, K;
vector<pair<int, int>> graph[20001];
vector<int> dist;

void input() {
	cin >> V >> E;
	cin >> K;
	int u, v, w;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		graph[u].push_back(make_pair(v, w));
	}
	dist.resize(V + 1);
	for (int i = 0; i <= V; i++)
		dist[i] = MAX;
}
void dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
	pq.push({ 0, K });
	dist[K] = 0;

	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < graph[cur].size(); i++) {
			int pnext = graph[cur][i].first;
			int pcost = graph[cur][i].second;
			if (dist[pnext] > cost + pcost) {
				dist[pnext] = cost + pcost;
				pq.push({ dist[pnext], pnext });
			}
		}
	}
}
void print() {
	for (int i = 1; i <= V; i++) {
		if (dist[i] == MAX)
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';
	}
}
void solution() {
	input();
	dijkstra();
	print();
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	solution();
	return 0;
}