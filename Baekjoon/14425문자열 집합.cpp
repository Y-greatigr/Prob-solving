#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	map<string, int> ab;
	string j;
	int count = 0;

	for (int i = 0; i < a; i++) {
		cin >> j;
		ab.insert(make_pair(j, 1));
	}
	for (int i = 0; i < b; i++) {
		cin >> j;
		if (ab[j] == 1)
			count++;
	}
	cout << count;
	return 0;
}