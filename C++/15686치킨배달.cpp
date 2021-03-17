#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int n, m, maxi = INT_MAX, num;
vector<pair<int, int>> h, c, v;
bool s[13] = { false };

int cal() {
	int wow = 0;
	for (int i = 0; i < h.size(); i++) {
		int a = h[i].first;
		int b = h[i].second;
		int d = INT_MAX;
		for (int j = 0; j < v.size(); j++)
			d = min(d, abs(v[j].first - a) + abs(v[j].second - b));
		wow += d;
	}
	return wow;
}
void select(int ind, int cnt) {
	if (cnt == m) {
		maxi=min(maxi, cal());
		return;
	}
	for (int i = ind; i < num; i++) {
		if (s[i])
			continue;
		s[i] = true;
		v.push_back(c[i]);
		select(i, cnt + 1);
		v.pop_back();
		s[i] = false;
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int a;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a;
			if (a == 1)
				h.push_back({ i,j });
			else if (a == 2)
				c.push_back({ i,j });
		}
	}
	num = c.size();
	select(0, 0);
	cout << maxi;
	return 0;
}