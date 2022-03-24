#include <iostream>
#include <queue>
using namespace std;

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second)
			return a.first < b.first;
		return a.second> b.second;
	}
};
priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;
int N;
void input() {
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		pq.push({ a,b });
	}
}
void solution() {
	int fin = pq.top().second;
	pq.pop();
	N--;
	int sum = 1;
	while (N--) {
		int a= pq.top().first;
		int b = pq.top().second;
		pq.pop();
		if (a >= fin) {
			fin = b;
			sum++;
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