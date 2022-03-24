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
			if (x.bronze == y.bronze)
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

	int n, k, e;
	cin >> n >> k;
	vector<a> b(n+1);

	for (int i = 1; i < n+1; i++)
		cin >> b[i].n >> b[i].gold >> b[i].silver >> b[i].bronze;
	sort(b.begin()+1, b.end(),com);
	
	int r = 1;
	for (int i = 1; i < n+1; i++) {
		if (b[i].gold == b[i - 1].gold && b[i].silver == b[i - 1].silver && b[i].bronze == b[i - 1].bronze) {
			b[i].rank = r;
		}
		else {
			r = i;
			b[i].rank = i;
		}
		if (b[i].n == k) {
			e = b[i].rank;
			break;
		}
	}
	cout << e;
	return 0;
}