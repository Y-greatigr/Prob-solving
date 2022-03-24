#include <iostream>
#include <queue>
using namespace std;

int N;
struct cmp {
	bool operator()(pair<int,int> a, pair<int,int> b) {
		return a.second > b.second;
	}
};
priority_queue<pair<int,int>, vector<pair<int, int>>, cmp> pq;
void input() {
	int a, b, c;
	cin >> c;
	N = c;
	while (c--) {
		cin >> a >> b;
		pq.push({ a, a + b });
	}
}
void solution() {
	int cnt = 1;
	int end = pq.top().second;
	N--;
	pq.pop();
	while (N--) {
		int start = pq.top().first;
		if (start <= end) {
			pq.pop();
			continue;
		}
		end = pq.top().second;
		cnt++;
		pq.pop();
	}
	cout << cnt;
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