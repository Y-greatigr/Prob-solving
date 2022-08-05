#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	string a = "IJKLABCDEFGH";
	string b = "6789012345";

	int n;
	cin >> n;

	int i = (n) % 12;
	int j = (n) % 10;

	cout << a[i] << b[j];

	return 0;
}