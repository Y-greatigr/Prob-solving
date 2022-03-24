#include <iostream>

using namespace std;
long long* arr;
long long* segtree;

long long segmenTree(int start, int end, int cur) {
	if (start == end)
		return segtree[cur] = arr[start];
	return segtree[cur] = segmenTree(start, (start + end) / 2, cur * 2) +
		segmenTree((start + end) / 2 + 1, end, cur * 2 + 1);
}
void change(int start, int end, int cur, int ind, long long dif) {
	if (start > ind || end < ind)
		return;
	segtree[cur] += dif;
	if (start == end)
		return;
	change(start, (start + end) / 2, cur * 2, ind, dif);
	change((start + end) / 2 + 1, end, cur * 2 + 1, ind, dif);
}
long long sum(int start, int end, int cur, int left, int right) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return segtree[cur];
	return sum(start, (start + end) / 2, cur * 2, left, right) +
		sum((start + end) / 2 + 1, end, cur * 2 + 1, left, right);
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n, m, k; cin >> n >> m >> k;
	arr = new long long[n + 1];
	segtree = new long long[4 * n - 1];
	
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	segmenTree(1, n, 1);

	int a;
	for (int i = 0; i < m + k; i++) {
		cin >> a;
		if (a == 1) {
			int b;
			long long c;
			cin >> b >> c;
			long long dif = c - arr[b];
			arr[b] = c;
			change(1, n, 1, b, dif);
		}
		else {
			int b, c;
			cin >> b >> c;
			cout << sum(1, n, 1, b, c) << '\n';
		}
	}

	return 0;
}