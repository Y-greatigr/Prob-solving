#include <iostream>
using namespace std;

int lcm(int M, int N) {
	int a = M, b = N;
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return M * N / a;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n;
	cin >> n;

	int M, N, x, y;
	while (n--) {
		cin >> M >> N >> x >> y;
		while(1) {
			if (x > lcm(M, N)) {
				cout << -1 << '\n';
				break;
			}
			if ((x - 1) % N + 1 == y) {
				cout << x << '\n';
				break;
			}
			x += M;
		}
	}
	return 0;
}