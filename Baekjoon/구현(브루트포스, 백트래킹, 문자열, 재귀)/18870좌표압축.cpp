#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n, x;
	cin >> n;

	vector<pair<int,int>> a;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a.push_back({ x, i });
	}
	sort(a.begin(), a.end());

	vector<int> c(n);
	c[a[0].second] = 0;
	int count = 0;
	for (int i = 0; i < n - 1; i++) {
		if (a[i].first == a[i + 1].first)
			c[a[i + 1].second] = count;
		else
			c[a[i + 1].second] = ++count;
	}

	for (int i = 0; i < n; i++)
		cout << c[i] << " ";

	return 0;
}