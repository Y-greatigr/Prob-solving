#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
vector<pair<int, int>> v;
int st_x, st_y, de_x, de_y, n;

bool bfs() {
	bool co[101] = { false, };
	queue<pair<int, int>> q;
	q.push(make_pair(st_x, st_y));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i <= n; i++) {
			if (!co[i] && abs(v[i].first - x) + abs(v[i].second - y) <= 1000) {
				co[i] = true;
				q.push(make_pair(v[i].first, v[i].second));
			}
		}
	}
	return co[n];
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t, x, y;
	cin >> t;
	while (t--) {
		cin >> n;
		cin >> st_x >> st_y;
		for (int i = 0; i < n; i++) {
			cin >> x >> y;
			v.push_back({ x, y });
		}
		cin >> de_x >> de_y;
		v.push_back({ de_x,de_y });
		if (bfs())
			cout << "happy" << '\n';
		else
			cout << "sad" << '\n';

		v.clear();
	}
	return 0;
}