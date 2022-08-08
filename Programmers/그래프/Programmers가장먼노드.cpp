#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

void bfs(int node, vector<vector<int>> edge, vector<int> &cnt) {
	queue<pair<int,int>>q; q.push({node, 0});
	bool visited[20001]; memset(visited, false, sizeof(visited));
	visited[node] = true;
	while (!q.empty()) {
		int cur = q.front().first; int count = q.front().second; 
		q.pop(); cnt[count]++;
		for (int i = 0; i < edge[cur].size(); i++) {
			if (visited[edge[cur][i]])continue;
			visited[edge[cur][i]] = true;
			q.push({ edge[cur][i] , count + 1 });
		}
	}
}
int solution(int n, vector<vector<int>> edge) {
	vector<vector<int>> a(n + 1);
	for (int i = 0; i < edge.size(); i++) {
		a[edge[i][0]].push_back(edge[i][1]);
		a[edge[i][1]].push_back(edge[i][0]);
	}
	vector<int> cnt(n);
	bfs(1, a, cnt);
	for (int i = n - 1; i >= 0; i--) {
		if (cnt[i])
			return cnt[i];
	}
	return 1;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<vector<int>> a = { {3, 6} ,{4, 3},{3, 2},{1, 3},{1, 2},{2, 4},{5, 2 } };
	cout << solution(6, a);
	return 0;
}