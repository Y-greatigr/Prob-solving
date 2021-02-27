#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool check;
bool visited[1001];
int ans;

vector<int> v[1001];

void prim(int st) {
	visited[st] = true;
	queue<int> q;

	for (int i = 0; i < v[st].size(); i++) {
		int next = v[st][i];
		q.push(next);
	}
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		if (visited[here])
			continue;
		visited[here] = true;
		ans++;
		for (int i = 0; i < v[here].size(); i++)
		{
			int there = v[here][i];
			q.push(there);
		}
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t; cin >> t;
	int n, m;
	while (t--) {
		ans = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			visited[i] = false;
			v[i].clear();
		}
		for (int i = 0; i < m; i++) {
			int d, e;
			cin >> d >> e;
			v[d].push_back(e);
			v[e].push_back(d);
		}
		prim(1);
		cout << ans << '\n';
	}
	return 0;
}