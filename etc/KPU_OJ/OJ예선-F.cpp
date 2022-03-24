#include <iostream>
using namespace std;

int arr[4][4];
char c;
void input() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> c;
}
void solution() {
	if (c == 'L') {		
		for (int i = 0; i < 4; i++) {
			int flag = 0;
			int loc = 3;
			for (int j = 3; j >= 0; j--) {
				if (flag && !arr[i][j]) {
					arr[i][j] = arr[i][loc];
					arr[i][loc] = 0;
					j = 4;
					flag = 0;
				}
				if (arr[i][j] != 0 && j != 4) {
					flag = 1;
					loc = j;
				}
			}
			if (arr[i][0] == arr[i][1]) {
				if (arr[i][2] == arr[i][3]) {
					arr[i][0] *= 2;
					arr[i][1] = arr[i][2] * 2;
					arr[i][2] = 0;
					arr[i][3] = 0;
				}
				else {
					arr[i][0] *= 2;
					arr[i][1] = arr[i][2];
					arr[i][2] = arr[i][3];
					arr[i][3] = 0;
				}
			}
			if (arr[i][1] == arr[i][2]) {
				arr[i][1] *= 2;
				arr[i][2] = arr[i][3];
				arr[i][3] = 0;
			}
			if (arr[i][2] == arr[i][3]) {
				arr[i][2] *= 2;
				arr[i][3] = 0;
			}
			flag = 0;
			loc = 3;
			for (int j = 3; j >= 0; j--) {
				if (flag && !arr[i][j]) {
					arr[i][j] = arr[i][loc];
					arr[i][loc] = 0;
					j = 4;
					flag = 0;
				}
				if (arr[i][j] != 0 && j!=4) { 
					flag = 1; 
					loc = j; 
				}
			}
		}
	}
	else if (c == 'R') {
		for (int i = 0; i < 4; i++) {
			int flag = 0;
			int loc = 0;
			for (int j = 0; j < 4; j++) {
				if (flag && !arr[i][j]) {
					arr[i][j] = arr[i][loc];
					arr[i][loc] = 0;
					j = -1;
					flag = 0;
				}
				if (arr[i][j] != 0 && j != -1) {
					flag = 1;
					loc = j;
				}
			}
			if (arr[i][2] == arr[i][3]) {
				if (arr[i][0] == arr[i][1]) {
					arr[i][3] *= 2;
					arr[i][2] = arr[i][1] * 2;
					arr[i][1] = 0;
					arr[i][0] = 0;
				}
				else {
					arr[i][3] *= 2;
					arr[i][2] = arr[i][1];
					arr[i][1] = arr[i][0];
					arr[i][0] = 0;
				}
			}
			else if (arr[i][1] == arr[i][2]) {
				arr[i][2] *= 2;
				arr[i][1] = arr[i][0];
				arr[i][0] = 0;
			}
			else if (arr[i][0] == arr[i][1]) {
				arr[i][1] *= 2;
				arr[i][0] = 0;
			}
			flag = 0;
			loc = 0;
			for (int j = 0; j<4; j++) {
				if (flag && !arr[i][j]) {
					arr[i][j] = arr[i][loc];
					arr[i][loc] = 0;
					j = -1;
					flag = 0;
				}
				if (arr[i][j] != 0 && j!=-1) {
					flag = 1;
					loc = j;
				}
			}
		}
	}
	else if (c == 'U') {
		for (int i = 0; i < 4; i++) {
			int flag = 0;
			int loc = 3;
			for (int j = 3; j >= 0; j--) {
				if (flag && !arr[j][i]) {
					arr[j][i] = arr[loc][i];
					arr[loc][i] = 0;
					j = 4;
					flag = 0;
				}
				if (arr[j][i] != 0 && j != 4) {
					flag = 1;
					loc = j;
				}
			}
			if (arr[0][i] == arr[1][i]) {
				if (arr[2][i] == arr[3][i]) {
					arr[0][i] *= 2;
					arr[1][i] = arr[2][i] * 2;
					arr[2][i] = 0;
					arr[3][i] = 0;
				}
				else {
					arr[0][i] *= 2;
					arr[1][i] = arr[2][i];
					arr[2][i] = arr[3][i];
					arr[3][i] = 0;
				}
			}
			else if (arr[1][i] == arr[2][i]) {
				arr[1][i] *= 2;
				arr[2][i] = arr[3][i];
				arr[3][i] = 0;
			}
			else if (arr[3][i] == arr[2][i]) {
				arr[2][i] *= 2;
				arr[3][i] = 0;
			}
			flag = 0;
			loc = 3;
			for (int j = 3; j >=0; j--) {
				if (flag && !arr[j][i]) {
					arr[j][i] = arr[loc][i];
					arr[loc][i] = 0;
					j = 4;
					flag = 0;
				}
				if (arr[j][i] != 0 && j != 4) {
					flag = 1;
					loc = j;
				}
			}
		}
	}
	else if (c == 'D') {
		for (int i = 0; i < 4; i++) {
			int flag = 0;
			int loc = 0;
			for (int j = 0; j < 4; j++) {
				if (flag && !arr[j][i]) {
					arr[j][i] = arr[loc][i];
					arr[loc][i] = 0;
					j = -1;
					flag = 0;
				}
				if (arr[j][i] != 0 && j != -1) {
					flag = 1;
					loc = j;
				}
			}
			if (arr[2][i] == arr[3][i]) {
				if (arr[0][i] == arr[1][i]) {
					arr[3][i] *= 2;
					arr[2][i] = arr[1][i] * 2;
					arr[1][i] = 0;
					arr[0][i] = 0;
				}
				else {
					arr[3][i] *= 2;
					arr[2][i] = arr[1][i];
					arr[1][i] = arr[0][i];
					arr[0][i] = 0;
				}
			}
			else if (arr[1][i] == arr[2][i]) {
				arr[2][i] *= 2;
				arr[1][i] = arr[0][i];
				arr[0][i] = 0;
			}
			else if (arr[0][i] == arr[1][i]) {
				arr[1][i] *= 2;
				arr[0][i] = 0;
			}
			flag = 0;
			loc = 0;
			for (int j = 0; j < 4; j++) {
				if (flag && !arr[j][i]) {
					arr[j][i] = arr[loc][i];
					arr[loc][i] = 0;
					j = -1;
					flag = 0;
				}
				if (arr[j][i] != 0 && j != -1) {
					flag = 1;
					loc = j;
				}
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (j == 3)cout << arr[i][j];
			else cout << arr[i][j] << " ";
		}
		if (i == 3) break;
		cout << '\n';
	}
}
void solve() {
	input();
	solution();
}
int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);
	solve();
	return 0;
}