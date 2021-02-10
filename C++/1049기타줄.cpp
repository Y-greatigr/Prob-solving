#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n, m;
	cin >> n >> m;

	vector<int> pack(m);
	vector<int> one(m);
	
	for (int i = 0; i < m; i++) {
		cin >> pack[i] >> one[i];
	}
	sort(pack.begin(), pack.end());
	sort(one.begin(), one.end());

	int a;
	if (n % 6 != 0)
		a = n / 6 + 1;
	else
		a = n / 6;
	
	int money = pack[0] * a;
	while (1) {
		a--;
		if (a == -1)
			break;
		int tmp = pack[0] * a + one[0] * (n - 6 * a);
		if (tmp < money)
			money = tmp;
	}

	cout << money;
	return 0;
}