#include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	
	if (n % 10)
		cout << -1;
	else
		cout << n/300 << " " << n%300/60 << " " << n%300%60/10;
	return 0;
}