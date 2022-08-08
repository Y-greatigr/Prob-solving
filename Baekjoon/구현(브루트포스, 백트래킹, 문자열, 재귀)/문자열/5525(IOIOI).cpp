#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int n, str_length; cin >> n >> str_length;
	string s; cin >> s;
	int count = 0, k = 0;

	for (int i = 1; i < str_length - 1; i++) {
		if (s[i - 1] == 'I' && s[i] == 'O' && s[i + 1] == 'I') {
			count++;
			if (count == n) {
				k++;
				count--;
			}
			i++;
		}
		else
			count = 0;
	}
	cout << k;
	return 0;
}