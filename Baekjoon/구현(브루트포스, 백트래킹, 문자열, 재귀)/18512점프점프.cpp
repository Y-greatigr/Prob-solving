#include <iostream>
#include<set>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int x, y, a1, a2;
	cin >> x >> y >> a1 >> a2;

	set<int> s;
	int dif;
	while (a1 != a2) {
		dif = a1 - a2;
		if (s.count(dif) > 0) {
			cout << -1;
			return 0;
		}
		else
			s.insert(dif);
		if (a1 > a2)
			a2 += y;
		else
			a1 += x;
	}
	cout << a1;

	return 0;
}