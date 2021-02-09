#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	string a;
	vector<int> v;
	int count = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == "push") {
			int k;
			cin >> k;
			v.push_back(k);
		}
		else if (a == "pop") {
			if (count >= v.size()) {
				cout << -1 << '\n';
				continue;
			}
			cout << v[count++] << '\n';
		}
		else if (a == "size") {
			cout << v.size() - count << '\n';
		}
		else if (a == "empty") {
			if ((v.size() - count) == 0)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (a == "front") {
			if (count >= v.size()) {
				cout << -1 << '\n';
				continue;
			}
			cout << v[count] << '\n';
		}
		else {
			if (count >= v.size()) {
				cout << -1 << '\n';
				continue;
			}
			cout << v[v.size()-1] << '\n';
		}
	}
	return 0;
}