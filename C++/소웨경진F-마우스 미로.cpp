#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;
string a[1000];
bool e(int mr, int mc, int dr, int dc) {

}
int main() {

	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int r, c, mr, mc, dr, dc;
	cin >> r >> c;

	string b;
	
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> b;
			if (b == "M") {
				mr = r;
				mc = c;
			}
			else if (b == "D") {
				dr = r;
				dc = c;
			}
			a[i].push_back(b);
		}
	}
	
	if (e(mr, mc, dr, dc)) {
		cout << "YES\n";
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cout << a[i][j];
			}
			cout << "\n";
		}
	}
	else
		cout << "NO\n";
	return 0;
}