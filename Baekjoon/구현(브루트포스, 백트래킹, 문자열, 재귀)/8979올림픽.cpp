#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class a {
public:
	int n, gold, silver, bronze, rank;
};
bool com(a x, a y) {
	if (x.gold == y.gold) {
		if (x.silver == y.silver) {
			return x.bronze > y.bronze;
		}
		return x.silver > y.silver;
	}
	else
		return x.gold > y.gold;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;
	vector<a> b(n);

	for (int i = 0; i < n; i++)
		cin >> b[i].n >> b[i].gold >> b[i].silver >> b[i].bronze;
	sort(b.begin(), b.end(), com);

	b[0].rank = 1;
	for (int i = 1; i < n; i++) {
		if (b[i].gold == b[i - 1].gold && b[i].silver == b[i - 1].silver && b[i].bronze == b[i - 1].bronze) {
			b[i].rank = b[i - 1].rank;
		}
		else {
			b[i].rank = i + 1;
		}
	}
	for (int i = 0; i < n; i++) {
		if (b[i].n == k) {
			cout << b[i].rank;
			break;
		}
	}
	return 0;
}