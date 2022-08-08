#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int N;
int a[10000];
void input() {
	cin >> N;
	for (int i = 0; i < 2 * N; i++) cin >> a[i];
	sort(a, a + 2 * N);
}
void solution() {
	int min = INT_MAX;
	for (int i = 0; i < N; i++) {
		int sum = a[i] + a[2 * N - i - 1];
		if (min > sum)min = sum;
	}
	cout << min;
}
void solve() {
	input();
	solution();
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}