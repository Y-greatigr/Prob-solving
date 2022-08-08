#include <iostream>
#include <vector>
using namespace std;

int fun(int n) {
	vector<int> a;

	for (int i = 1; i < n; i++) {
		int sum = i;
		int b = i;
		int c;
		while (b >= 10) {
			c = b % 10;
			sum += c;
			b = b / 10;			
		}
		sum += b;
		if (sum == n)
			a.push_back(i);
	}
	if (a.size() > 0)
		return a[0];
	else
		return 0;
}
int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	cout<<fun(N);

	return 0;
}