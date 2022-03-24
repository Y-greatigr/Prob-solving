#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct cmp {
	bool operator()(vector<int> a, vector<int> b) {
		int size = a.size() < b.size() ? a.size() : b.size();
		for (int i = 0; i < size; i++) {
			if (a[i] == b[i])
				continue;
			return a[i] > b[i];
		}
		return a > b;
	}
};
int N;
priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

void input() {
	cin >> N;
	int x;
	for (int i = 0; i < N; i++) {
		vector<int> v;
		while (cin >> x) {
			if (x == -1)
				break;
			v.push_back(x);
		}
		pq.push(v);
	}
}
void solution() {
	for (int i = 0; i < N; i++) {
		vector<int> v = pq.top();
		pq.pop();
		cout << v[0];
		for (int j = 1; j < v.size(); j++)
			cout << " " << v[j];
		cout << '\n';
	}
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