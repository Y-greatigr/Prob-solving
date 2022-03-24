#include <iostream>
#include <vector>
using namespace std;

bool check;
int parent[1001];

class a {
public:
	int from, to;
};
vector<a> v;
int find(int u) {
	if (u == parent[u])
		return u;
	return parent[u] = find(parent[u]);
}
void merge(int from, int to) {
	check = false;
	from = find(from);
	to = find(to);

	if (from == to)
		return;

	parent[from] = to;
	check = true;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t; cin >> t;
	int n, m;
	while (t--) {
		v.clear();
		int ans = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}
		for (int i = 0; i < m; i++) {
			a d;
			cin >> d.from >> d.to;
			v.push_back(d);
		}
		for (int i = 0; i < m; i++) {
			merge(v[i].from, v[i].to);
			if (check)
				ans++;
		}
		cout << ans << '\n';
	}
	return 0;
}