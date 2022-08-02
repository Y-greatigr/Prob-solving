#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<pair<int, bool>> v;
int a[8] = { 0 };

void combi(int ind, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << a[i] << " ";
		}
		cout << '\n';
		return;
	}
	for (int i = ind; i < n; i++) {
		if (v[i].second)
			continue;
		a[cnt] = v[i].first;
		combi(i, cnt + 1);
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
	for (int i = 0; i < n - 1; i++) {
		if (v[i].first == v[i + 1].first)
			v[i + 1].second = true;
	}
	combi(0, 0);
	return 0;
}