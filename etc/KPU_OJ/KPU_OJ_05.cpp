#include <iostream>
#include <algorithm>
using namespace std;

int C, N;
pair<int, int> a[100001];
bool cmp(pair<int, int> i, pair<int, int> j) {
	return i.second > j.second;
}
void input() {
	cin >> C >> N;
	int b;
	while (N--) {
		cin >> b;
		int c = a[b].second;
		a[b] = { b, c + 1 };
	}
}
void solution() {
	sort(a, a + C + 1, cmp);
	cout << a[2].first;
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