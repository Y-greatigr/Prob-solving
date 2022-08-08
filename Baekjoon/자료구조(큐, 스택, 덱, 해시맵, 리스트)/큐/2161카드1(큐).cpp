#include <iostream>
#include <deque>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n; cin >> n;
	deque<int> d(n);
	for (int i = 0; i < n; i++)
		d[i] = i + 1;

	while (d.size() > 1) {
		cout << d.front() << " ";
		d.pop_front();
		d.push_back(d.front());
		d.pop_front();
	}
	cout << d.front();
	return 0;
}