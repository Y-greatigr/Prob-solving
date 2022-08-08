#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int* arr;
int* segtree;

int segmenTree(int start, int end, int cur) {
	if (start == end)
		return segtree[cur] = arr[start];
	return segtree[cur] = min(segmenTree(start, (start + end) / 2, cur * 2), 
		segmenTree((start + end) / 2 + 1, end, cur * 2 + 1));
}
int print(int start, int end, int cur, int left, int right) {
	if (right<start || left>end)
		return INT_MAX;
	else if (left <= start && right >= end)
		return segtree[cur];
	return min(print(start, (start + end) / 2, cur * 2, left, right), print((start + end) / 2 + 1, end, cur * 2 + 1, left, right));
}
int change(int start, int end, int cur, int ind) {
	if (start > ind || end < ind)
		return segtree[cur];
	if (start == end)
		return segtree[cur] = arr[ind];
	return segtree[cur] = min(change(start, (start + end) / 2, cur * 2, ind), change((start + end) / 2 + 1, end, cur * 2 + 1, ind));
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n; cin >> n;
	arr = new int[n + 1];
	segtree = new int[4 * n - 1];

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	segmenTree(1, n, 1);

	int m; cin >> m;
	int a, b, c;
	while(m--) {
		cin >> a >> b >> c;
		if (a == 1) {
			arr[b] = c;
			change(1, n, 1, b);
		}
		else {
			cout << print(1, n, 1, b, c) << '\n';
		}
	}
	return 0;
}