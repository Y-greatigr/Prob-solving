#include <iostream>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> a(10);
	int k;

	for (int i = 0; i < 10; i++) {
		cin >> a[i];
	}

	int a_win = 0, b_win = 0;
	for (int i = 0; i < 10; i++) {
		cin >> k;
		if (a[i] > k)
			a_win++;
		else if (a[i] < k)
			b_win++;
	}

	if (a_win > b_win)
		cout << "A";
	else if (a_win < b_win)
		cout << "B";
	else
		cout << "D";

	return 0;
}