#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a;

int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	a.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());

	int m, d;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> d;
		int left = 0, right = n - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (a[mid] > d)
				right = mid - 1;
			else if (a[mid] < d)
				left = mid + 1;
			else {
				cout << 1 << '\n';
				break;
			}
		}
		if (left > right)
			cout << 0 << '\n';
	}

	return 0;
}