#include <iostream>
#include <cmath>
using namespace std;
int n, r, c;
int co = 0;

void z(int a, int b, int po) {
	if (po < 0)
		return;
	int x = pow(2, po)/2;
	if (r < a+x) {
		if (c < b+x)
			z(a, b, po - 1);
		else {
			z(a, b+x, po - 1);
			co += x * x;
		}
	}
	else {
		if (c < b+x) {
			z(a+x, b, po - 1);
			co += 2 * x * x;
		}
		else {
			z(a + x, b + x, po - 1);
			co += 3 * x * x;
		}
	}
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> r >> c;
	z(0,0,n);
	cout << co;
	return 0;
}