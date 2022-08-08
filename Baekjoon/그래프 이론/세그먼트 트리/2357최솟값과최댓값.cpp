#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int* arr;
int* minTree;
int* maxTree;

int miniTree(int start, int end, int cur) {
	if (start == end)
		return minTree[cur] = arr[start];
	return minTree[cur] = min(miniTree(start, (start + end) / 2, cur * 2),
		miniTree((start + end) / 2 + 1, end, cur * 2 + 1));
}
int print(int start, int end, int cur, int left, int right) {
	if (right<start || left>end)
		return INT_MAX;
	else if (left <= start && right >= end)
		return minTree[cur];
	return min(print(start, (start + end) / 2, cur * 2, left, right), 
		print((start + end) / 2 + 1, end, cur * 2 + 1, left, right));
}
int maxiTree(int start, int end, int cur) {
	if (start == end)
		return maxTree[cur] = arr[start];
	return maxTree[cur] = max(maxiTree(start, (start + end) / 2, cur * 2),
		maxiTree((start + end) / 2 + 1, end, cur * 2 + 1));
}
int mprint(int start, int end, int cur, int left, int right) {
	if (right<start || left>end)
		return INT_MIN;
	else if (left <= start && right >= end)
		return maxTree[cur];
	return max(mprint(start, (start + end) / 2, cur * 2, left, right),
		mprint((start + end) / 2 + 1, end, cur * 2 + 1, left, right));
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n, m; cin >> n >> m;
	arr = new int[n + 1];
	minTree = new int[4 * n - 1];
	maxTree = new int[4 * n - 1];

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	miniTree(1, n, 1);
	maxiTree(1, n, 1);

	int a, b;
	while (m--) {
		cin >> a >> b;
		cout << print(1, n, 1, a, b)<< " ";
		cout << mprint(1, n, 1, a, b) << '\n';
	}
	return 0;
}