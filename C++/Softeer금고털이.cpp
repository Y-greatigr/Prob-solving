#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		return a.second < b.second;
	}
};
int W, N;
priority_queue < pair<int, int>, vector<pair<int, int>>, cmp> pq;
void input() {
	cin >> W >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		pq.push({ a,b });
	}
}
void solution() {
	int n = 0;
	int sum = 0;
	while (n < W) {
		int m = pq.top().first;
		int p = pq.top().second;
		pq.pop();
		if (W - n >= m) {
			sum += m * p;
			n += m;
		}
		else {
			sum += (W - n) * p;
			break;
		}
	}
	cout << sum;
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