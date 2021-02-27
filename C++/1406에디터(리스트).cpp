#include <iostream>
#include <string>
#include <list>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	string s; cin >> s;
	list<char> li(s.begin(), s.end());
	list<char>::iterator cursor = li.end();
	char c;
	int n; cin >> n;

	while (n--) {
		cin >> c;
		if (c == 'L') {
			if (cursor != li.begin())
				cursor--;
		}
		else if (c == 'D') {
			if (cursor != li.end())
				cursor++;
		}
		else if (c == 'B') {
			if (cursor != li.begin()) {
				cursor = li.erase(--cursor);
			}
		}
		else {
			cin >> c;
			li.insert(cursor, c);
		}
	}
	for (cursor = li.begin(); cursor != li.end(); cursor++) {
		cout << *cursor;
	}
	return 0;
}