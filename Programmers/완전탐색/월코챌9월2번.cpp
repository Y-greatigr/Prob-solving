#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int xx[4] = { 0,0,1,-1 };
int yy[4] = { 1,-1,0,0 };
vector<int> solution(vector<string> grid) {
	vector<int> answer;
	map<pair<pair<int, int>, int>, int> m;
	int x_max = grid.size(), y_max = grid[0].length();
	for (int j = 0; j < x_max; j++) {
		for (int k = 0; k < y_max; k++) {
			for (int i = 0; i < 4; i++) {
				int cnt = 0, flag = 0;
				int x = j, y = k, direction = i;
				do {
					if (m[{ {x, y}, direction}]) {
						flag = 1; break;
					}
					m[{ {x, y}, direction}] = 1;

					x = x + xx[direction];
					y = y + yy[direction];
					if (x >= x_max)x = 0;
					else if (x < 0)x = x = x_max - 1;
					if (y >= y_max)y = 0;
					else if (y < 0)y = y_max - 1;

					if (grid[x][y] == 'L') {
						if (direction == 0) direction = 3;
						else if (direction == 1) direction = 2;
						else if (direction == 2) direction = 0;
						else if (direction == 3) direction = 1;
					}
					else if (grid[x][y] == 'R') {
						if (direction == 0) direction = 2;
						else if (direction == 1) direction = 3;
						else if (direction == 2) direction = 1;
						else if (direction == 3) direction = 0;
					}
					cnt++;
				} while ((x != j || y != k || direction != i));
				if (flag) continue;
				answer.push_back(cnt);
			}
		}
	}
	
	sort(answer.begin(), answer.end());
	return answer;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<string> v = { "S" };

	//vector<string> v = { "R", "R" };

	//vector<string> v = { "SL","LR"};

	vector<int> a = solution(v);
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << endl;
	return 0;
}