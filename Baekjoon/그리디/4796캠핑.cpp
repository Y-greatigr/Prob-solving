#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int l, p, v;

	int i = 1;
	while (1) {
		cin >> l >> p >> v;
		if (l == 0)
			break;
		int a = v / p;
		v = v % p;
		if (v >= l)
			l = l * (a + 1);
		else
			l = l * a + v;
		cout << "Case " << i++ << ": " << l << '\n';
	}
	
	return 0;
}