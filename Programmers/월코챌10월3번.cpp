#include <vector>
#include <iostream>

using namespace std;

long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
	long long answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int row = i, col = j;
			for (int k = 0; k < queries.size(); k++) {
				int command = queries[k][0];
				int dx = queries[k][1];
				if (command == 0)col -= dx;
				else if (command == 1)col += dx;
				else if (command == 2)row -= dx;
				else row += dx;
				if (row < 0)row = 0;
				if (col < 0)col = 0;
				if (row >= n)row = n - 1;
				if (col >= m)col = m - 1;
			}
			if (row == x && col == y)
				answer++;
		}
	}
	return answer;
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cout << solution(2, 2, 0, 0, { {2,1},{0,1},{1,1},{0,1},{2,1} });
	//cout << solution(2, 5, 0, 1, { {3,1},{2,2},{1,1},{2,3},{0,1},{2,1} });

	return 0;
}