#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
vector<pair<int, bool>> v;
int a[8] = { 0 };
void wow(int ind, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (v[i].second)
			continue;
		a[cnt] = v[i].first;
		v[i].second = true;
		wow(i, cnt + 1);
		v[i].second = false;
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	v.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i].first;
		v[i].second = false;
	}
	sort(v.begin(), v.end());
	wow(0, 0);
	return 0;
}