#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a;
int up(int k, int n) {
	int start = 0;
	int end = n - 1;
	while (start < end) {
		int mid = (start + end) / 2;
		if (a[mid] <= k)
			start = mid + 1;
		else
			end = mid;
	}
	if (a[end] != k)
		end--;
	return end;
}
int low(int k, int n) {
	int start = 0;
	int end = n - 1;
	while (start < end) {
		int mid = (start + end) / 2;
		if (a[mid] < k)
			start = mid + 1;
		else
			end = mid;
	}
	return end;
}
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
		int c = up(d, n);
		int e = low(d, n);
		if (a[c] != d)
			cout << 0 << " ";
		else
			cout << c - e + 1 << " ";
	}

	return 0;
}