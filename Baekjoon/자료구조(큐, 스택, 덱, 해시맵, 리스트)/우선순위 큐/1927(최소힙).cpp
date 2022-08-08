#include <iostream>
#include <queue>
using namespace std;
int main() {
	priority_queue< int, vector<int>, greater<int> > pq; //greater:ÃÖ¼ÒÈü, less:ÃÖ´ëÈü
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n;
	while (n--) {
		cin >> k;
		if (k == 0) {
			if (pq.size() == 0) {
				cout << '0' << '\n';
				continue;
			}
			cout << pq.top() << '\n';
			pq.pop();
		}
		else {
			pq.push(k);
		}
	}
	return 0;
}