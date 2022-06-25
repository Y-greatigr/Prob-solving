#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int>v(n);

	for (int i = 0; i < n; i++) {
		v[i] = i + 1;
	}
	int count = 0;
	while (true) {
		if (v.size() - 1 == count)
			break;
		v.push_back(v[count + 1]);
		count += 2;
	}
	cout << v[count];

	return 0;
}