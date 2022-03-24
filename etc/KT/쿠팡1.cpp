#include <iostream>
using namespace std;

int solution(int n);
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	cout << solution(n);
	return 0;
}
int solution(int n) {
	int sum = 0;
	while (n > 0) {
		sum += n % 10;
		n = n / 10;
	}
	return sum;
}
