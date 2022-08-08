#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<pair<int, int>, int>> v;
bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
	if (a.first.second == b.first.second)
		return a.first.first < b.first.first;
	return a.first.second < b.first.second;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t, c; cin >> t >> c;
	int m; cin >> m;
	while(m--) {
		int from, to, cp;
		cin >> from >> to >> cp;
		v.push_back(make_pair(make_pair(from, to), cp));
	}
	sort(v.begin(), v.end(), cmp);

	vector<int> tr(2001);
	int hungry = 0;
	for (int i = 0; i < v.size(); i++) {
		int get = 0;
		int st = v[i].first.first;
		int en = v[i].first.second;
		for (int j = st; j < en; j++)
			get = max(get, tr[j]);
		get = min(c - get, v[i].second);
		hungry += get;
		for (int j = st; j < en; j++)
			tr[j] += get;
	}
	cout << hungry;
	return 0;
}