#include <iostream>
using namespace std;
int a[5][5];
bool b[5][5] = { false, };
void draw(int what) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (a[i][j] == what)
				b[i][j] = true;
		}
	}
}
bool ans() {
	int count = 0;
	for (int i = 0; i < 5; i++) {
		if (b[i][0] == true && b[i][1] == true && b[i][2] == true && b[i][3] == true && b[i][4] == true)
			count++;
		if (b[0][i] == true && b[1][i] == true && b[2][i] == true && b[3][i] == true && b[4][i] == true)
			count++;
	}
	if (b[0][4] == true && b[1][3] == true && b[2][2] == true && b[3][1] == true && b[4][0] == true)
		count++;
	if (b[0][0] == true && b[1][1] == true && b[2][2] == true && b[3][3] == true && b[4][4] == true)
		count++;
	if (count >= 3)
		return true;
	else
		return false;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++)
			cin >> a[i][j];
	}
	int voice;
	int count = 1;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> voice;
			draw(voice);
			if (count > 11) {
				if (ans()) {
					cout << count;
					return 0;
				}
			}

			count++;
		}
	}
	return 0;
}