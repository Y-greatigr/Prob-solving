#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> a = { 0, };
vector<bool> visited = { false, };
void dfs(int k) {
	if (k == m + 1) {
		for (int i = 1; i <= m; i++)
			cout << a[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			a[k] = i;
			dfs(k + 1);
			visited[i] = false;
		}
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	a.resize(n + 1);
	visited.resize(n + 1);
	dfs(1);
	return 0;
}