#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	string s;
	cin >> s;

	int height = 10;
	char c = s[0];
	for (int i = 1; i < s.length(); i++) {
		if (s[i] == c)
			height += 5;
		else {
			height += 10;
			c = s[i];
		}
	}
	cout << height;

	return 0;
}