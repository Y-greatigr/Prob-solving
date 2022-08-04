#include <iostream>
#include <queue>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t, p; cin >> t;
	while (t--) {
		priority_queue<int, vector<int>, greater<int>> minheap;
		priority_queue<int, vector<int>, less<int>> maxheap;
		int m; cin >> m;
		cout << m / 2 + 1 << '\n';
		int center;
		cin >> p;
		center = p;
		cout << center << " ";
		for (int i = 1; i < m; i++) {
			cin >> p;
			if (p < center)
				maxheap.push(p);
			else
				minheap.push(p);
			if (i % 2 == 0) {
				if (minheap.size() < maxheap.size()) {
					minheap.push(center);
					center = maxheap.top();
					maxheap.pop();
					cout << center << " ";
				}
				else if (minheap.size() > maxheap.size()) {
					maxheap.push(center);
					center = minheap.top();
					minheap.pop();
					cout << center << " ";
				}
				else {
					cout << center << " ";
				}
			}
		}
		cout << '\n';
	}
	return 0;
}