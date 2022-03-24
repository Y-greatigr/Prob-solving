#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;

	string a;
	vector<int>v(21);
	while (n--) {
		cin >> a;
		if (a[1] == 'd') { //add
			int x;
			cin >> x;
			v[x] = x;
		}
		else if (a[1] == 'e') { //remove
			int x;
			cin >> x;
			v[x] = 0;
		}
		else if (a[1] == 'h') { //check
			int x;
			cin >> x;
			if (v[x] > 0)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (a[1] == 'o') { //toggle
			int x;
			cin >> x;
			if (v[x] > 0)
				v[x] = 0;
			else
				v[x] = x;
		}
		else if (a[1] == 'l') { //all
			for (int i = 1; i <= 20; i++)
				v[i] = i;
		}
		else { //empty
			for (int i = 1; i <= 20; i++)
				v[i] = 0;
		}
	}
	return 0;
}